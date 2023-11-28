#include <bits/stdc++.h>
using namespace std;

int n, m;

struct edge {
    int s, e, w;

};
bool comp(edge &a, edge &b) {
    return a.w < b.w;
}
vector<edge> v;
vector<int> g[200100];
int par[200100];
int val[200100];
int cn[200100];
int depth[200100];
int dp[200100][19];

int find(int x) {
    if (par[x]==x) return x;
    return par[x] = find(par[x]);
}
void kruskal() {
    int cnt = 0;
    for(int i=0; i<=n*2; i++) par[i] = i;
    for(int i=0; i<=n; i++) cn[i] = 1;

    for(int i=0; i<m; i++) {
        int x = find(v[i].s), y = find(v[i].e);
        if (x!=y) {
            n++;
            g[n].push_back(x);
            g[n].push_back(y);
            par[x] = n;
            par[y] = n;
            val[n] = v[i].w;
            cn[n] = cn[x]+cn[y];
            cnt += 1;
        }
        if (cnt==n-1) break;
    }
}

void dfs(int s, int p, int d) {
    depth[s] = d;
    for(int e: g[s]) {
        if (s==e) continue;
        dp[e][0] = s;
        dfs(e, s, d+1);
    }
}
void init() {
    for(int j=1; j<19; j++) {
        for(int i=0; i<n; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for(int i=0; diff; i++) {
        if (diff & 1) x = dp[x][i];
        diff >>= 1;
    }
    if (x==y) return x;
    for(int i=18; i>=0; i--) {
        if (dp[x][i]!=dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}


int main() {
    cin >> n >> m;
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=0; i<m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        v.push_back({s, e, w});
    }
    sort(v.begin(), v.end(), comp);
    kruskal();
    for(int i=1; i<=n; i++) {
        if (par[i]==i) dfs(i, i, 0);
    }
    init();
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        if (find(x)!= find(y)) {
            cout << -1 << '\n';
        } else {
            int node = lca(x,y);
            cout << val[node] << ' ' << cn[node] << '\n';
        }
    }
}