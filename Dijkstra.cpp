#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

vector<p> g[20001];
int dist[20001];
int par[20001];
int n;

void dijkstra(int v) {
    priority_queue<p> pq;
    pq.push({0, v}); dist[v] = 0;

    while(!pq.empty()) {
        int now = pq.top().y;
        int cost = -pq.top().x;
        pq.pop();

        if(cost > dist[now]) continue;

        for(auto i: g[now]) {
            int nxt = i.x;
            int nxtCost = cost + i.y;
            if (nxtCost < dist[nxt]) {
                nxtCost = dist[nxt];
                pq.push({-nxtCost, nxt});
                par[nxt] = now;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) dist[i] = 1e9;
    for(int i=1; i<=n; i++) par[i] = -1;
    dijkstra(1);
}