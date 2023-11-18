#include <bits/stdc++.h>
using namespace std;
int n, m, mv, rv;
int dp[1<<13][13][2];

vector<pair<int, int>> g[13];

struct Data{
    int cost = 0;
    int node = 0;
    int vst = 0;
    bool isR = 0;

    bool operator < (const Data &d) {
        return cost < d.cost;
    }

};


int dijkstra(int start) {
    int ans = 1e9;
    priority_queue<Data> pq;
    pq.push({0, start, 1<<start, 0});
    pq.push({0, start, 1<<start, 1});
    dp[1<<start][start][0] = 0;
    dp[1<<start][start][1] = 0;

    while (!pq.empty()) {
        auto here = pq.top(); pq.pop();
        if (here.vst==1<<13-1) {
            ans = min(ans, here.cost);
            continue;
        }
        for(auto i: g[here.node]) {
            int nxt = i.first, nCost = here.cost*((here.isR) ? rv : mv) + i.second;
            int nVst = here.vst^(1<<nxt);
            if (nVst == here.vst) continue;
            if (dp[nVst][nxt][here.isR] > nCost) {
                dp[nVst][nxt][here.isR] = nCost;
                pq.push({nCost, nxt, nVst, here.isR});
            }
        }
    }
    if (ans!=1e9) return ans;
    else return 0;
}


int main() {
    cin >> n >> m >> mv >> rv;
    while(m--) {
        int u, v, c; cin >> u >> v >> c;
        g[u-1].push_back({v-1, c});
    }
    int ans = 1e9;
    for (int i=0; i<n; i++) {
        int t = dijkstra(i);
        if (t) ans = min(ans, t);
    }
    cout << ans;
}