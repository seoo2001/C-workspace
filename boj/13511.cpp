#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<pair<ll, ll>> g[100100];
ll depth[100100];
ll dp[100100][30];
ll wdp[100100][30];
bool visited[100100];

void dfs(ll v, ll d) {
    visited[v] = 1;
    depth[v] = d;
    for(auto i : g[v]) {
        if(!visited[i.first]) {
            dp[i.first][0] = v;
            wdp[i.first][0] = i.second;
            dfs(i.first, d+1);
        }
    }
}

void init() {
    for(int j=1; j<30; j++) {
        for(int i=1; i<=n; i++) {
            dp[i][j] = dp[ dp[i][j-1] ][j-1];
            wdp[i][j] = wdp[i][j-1] + wdp[ dp[i][j-1] ][j-1];
        }
    }
}

ll findp(ll v, ll n) {
    for(int i=0; n; i++) {
        if (n & 1) {
            v = dp[v][i];
        }
        n >>= 1;
    }
    return v;
}

ll query1(ll u, ll v) {
    ll cost = 0;
    if(depth[u] < depth[v]) swap(u, v);
    ll diff = depth[u]-depth[v];
    for(int i=0; diff; i++) {
        if (diff & 1) {
            cost += wdp[u][i];
            u = dp[u][i];
        }
        diff >>= 1;
    }
    if (u==v) return cost;
    for(int i=29; i>=0; i--) {
        if (dp[u][i]!=dp[v][i]) {
            cost += wdp[u][i]+wdp[v][i];
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return cost + wdp[u][0] + wdp[v][0];
}


ll query2(ll u, ll v, ll k) {
    ll ut = u, vt = v;
    bool ch = false;
    if(depth[u] < depth[v]) {
        swap(u, v);
        ch = true;
    }
    ll diff = depth[u]-depth[v];
    u = findp(u, diff);

    if (u==v) {
        if (ch) {
            ll dd = depth[vt] - depth[v];
            ll tp = dd-(k-1);
            return findp(vt, tp);
        } else {
            ll tp = k-1;
            return findp(ut, tp);
        }
    }

    for(int i=29; i>=0; i--) {
        if (dp[u][i]!=dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    ll dh = depth[dp[u][0]];
    if (k-1<=depth[ut]-dh) {
        return findp(ut, k-1);
    } else {
        ll tp = depth[ut]+depth[vt]-dh*2 + 1 - k;
        return findp(vt, tp); 
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dfs(1, 0);
    init();
    int m; cin >> m;
    while(m--) {
        int c; cin >> c;
        if(c==1) {
            ll a, b; cin >> a >> b;
            cout << query1(a,b) << '\n';
        } else {
            ll a, b, k; cin >> a >> b >> k;
            cout << query2(a,b,k) << '\n';
        }
    }
    return 0;
}