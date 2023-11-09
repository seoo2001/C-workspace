#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, ll>> g[1005];
int par[1005];
ll cst[1005];
int n, m;
int s, e;
void dijkstra() {
    fill(cst, cst+1001, 1e9);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int now = pq.top().second;
        ll cost = -pq.top().first;
        pq.pop();
        if (cost > cst[now]) continue;
        cst[now] = cost;
        for(auto i: g[now]) {
            int nxt = i.first;
            ll nxtCost = cost + i.second;
            if (cst[nxt] > nxtCost) {
                cst[nxt] = nxtCost;
                pq.push({-nxtCost, nxt});
                par[nxt] = now;
            }
        }
    }
}

void order(int x, int i) {
    if (x==s) cout << i << '\n';
    else order(par[x], i+1);
    cout << x << ' ';
}

int main() {
    cin >> n >> m;
    while(m--) {
        int u, v; ll w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    cin >> s >> e;
    dijkstra();
    cout << cst[e] << '\n';
    order(e, 1);
}