#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n, k;
int s, e;

vector<pair<int, ll>> g[30005];
map<int, map<int,bool>> fb[30005];

struct qdata {
    ll cost;
    int node;
    int pre;
    bool operator < (const qdata &d) const {
        return cost < d.cost;
    }
};

map<int, ll> c[30005];

int dijkstra() {
    priority_queue<qdata> pq;
    pq.push({0, s, s});
    while (!pq.empty()) {
        qdata qd = pq.top(); pq.pop();
        ll cost = -qd.cost; int node = qd.node, pre = qd.pre;

        if (c[node][pre]!=0) {
            if (c[node][pre] < cost) continue;
        }
        c[node][pre] = cost;

        for(auto nd : g[node]) {
            int nxtNode = nd.first;
            ll nxtCost = cost + nd.second;
            if (fb[node][pre][nxtNode]) continue;
            if (c[nxtNode][node]!=0) {
                if (c[nxtNode][node] < nxtCost) continue;
            }
            c[nxtNode][node] = nxtCost;
            pq.push({-nxtCost, nxtNode, node});
        }
    }
    ll ans=1e11;
    for (auto i: c[e]) ans = min(ans, i.second);
    if (ans==1e11) return -1;
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> k;
    cin >> s >> e;
    for (int i=0; i<m; i++) {
        int v, w; ll val;
        cin >> v >> w >> val;
        g[v].push_back({w,val});
    }
    for (int i=0; i<k; i++) {
        int v, w, u; cin >> v >> w >> u;
        fb[w][v][u] = true;
    }
    if (s==e) cout << 0;
    else cout << dijkstra();
}