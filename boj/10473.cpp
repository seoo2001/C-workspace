#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<double, double> p;

double sx, sy, ex, ey;
double g[105][105];
p loc[105];
double dis[105];
int n;

void dijkstra() {
    priority_queue<pair<double, int>> pq;
    pq.push({0.0, 0}); dis[0] = 0.0;
    while(!pq.empty()) {
        double cost = -pq.top().x;
        int now = pq.top().y;
        pq.pop();
        if (cost > dis[now]) continue;
        for (int i=0; i<=n+1; i++) {
            double nxtCost = cost + g[now][i];
            if (nxtCost < dis[i]) {
                dis[i] = nxtCost;
                pq.push({-nxtCost, i});
            }
        }
    }
}

double cald(int u, int v) {
    return pow(pow(loc[u].x-loc[v].x, 2)+pow(loc[u].y-loc[v].y, 2), 0.5);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> sx >> sy; cin >> ex >> ey;
    cin >> n;
    
    loc[0] = {sx, sy}; loc[n+1] = {ex, ey};
    
    for(int i=1; i<=n; i++) {
        double a, b; cin >> a >> b;
        loc[i] = {a, b};
    }

    for(int i=1; i<=n+1; i++) g[0][i] = cald(0, i)/5.0; 
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n+1; j++) {
            double d = cald(i,j);
            g[i][j] = min(d/5.0, 2.0 + abs(d-50)/5);
            g[j][i] = min(d/5.0, 2.0 + abs(d-50)/5);
        }
    }
    for(int i=0; i<105; i++) dis[i] = 1e9;
    dijkstra();
    cout << dis[n+1];
}