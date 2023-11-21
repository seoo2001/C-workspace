#include <bits/stdc++.h>

using namespace std;

int n, pv, rv;
vector<pair<int,int>> g[13];
int dp[13][13][1<<13]; // 13 * 13 * 8000 = 2000000

struct qd {
    int t, px, rx, vis;
    qd(int t, int px, int rx, int vis): t(t), px(px), rx(rx), vis(vis) {}
    
};

struct comp {
    bool operator() (const qd &q1, const qd &q2) {
        return q1.t < q2.t;
    }
};

int dijkstra(int start) {
    memset(dp, -1, sizeof(dp));
    priority_queue<qd, vector<qd>, comp> pq;
    pq.push({0, start, start, 1<<start});
    pq.push({0, start, start, 1<<start});
    while (!pq.empty()) {
        qd now = pq.top(); pq.pop();
        cout << now.vis << now.px << now.rx << '\n';
        if (dp[now.px][now.rx][now.vis]!= -1 && dp[now.px][now.rx][now.vis]<now.t) continue;
        for(auto i: g[now.px]) {
            int nxt = i.first;
            int nt = -now.t+i.second*(pv);
            int nvis = now.vis^(1<<nxt);
            if (dp[nxt][now.rx][nvis]== -1 || dp[nxt][now.rx][nvis]>nt) {
                dp[nxt][now.rx][nvis] = nt;
                pq.push({-nt, nxt, now.rx, nvis});
            }
        }
        for(auto i: g[now.rx]) {
            int nxt = i.first;
            int nt = -now.t+i.second*(pv);
            int nvis = now.vis^(1<<nxt);
            if (dp[now.px][nxt][nvis]== -1 || dp[now.px][nxt][nvis]>nt) {
                dp[now.px][nxt][nvis] = nt;
                pq.push({-nt, now.px, nxt, nvis});
            }
        }
    }
    int ans = 1e9;
    for(int i=0;i<n; i++) 
        if (dp[i][i][1<<n-1]!=-1) ans = min(ans, dp[i][i][1<<n-1]);
    return ans;
}

int main() {
    int m; cin >> n >> m >> pv >> rv;
    while(m--) {
        int x, y, l; cin >> x >> y >> l;
        g[x-1].push_back({y-1,l});
    }
    int answer = 1e9;
    for(int i=0; i<n; i++) answer = min(answer, dijkstra(i));
    cout << answer;
}