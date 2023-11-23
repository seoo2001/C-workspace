#include <bits/stdc++.h>

using namespace std;
// 200 000 000
int n, pv, rv;
vector<pair<int,int>> g[12];
int dp[12][12][1<<12]; // 12 * 12 * 4000 = 600 000
int answer = 1e9;

struct qd {
    int mt, pt, rt, px, rx, vis;
    qd(int mt, int pt, int rt, int px, int rx, int vis): mt(mt), pt(pt), rt(rt), px(px), rx(rx), vis(vis) {}
};

struct comp {
    bool operator() (const qd &q1, const qd &q2) {
        return q1.mt < q2.mt;
    }
};

int dijkstra(int start) {
    fill_n(&dp[0][0][0], 12 * 12 * (1<<12), answer);
    priority_queue<qd, vector<qd>, comp> pq;
    pq.push({0, 0, 0, start, start, 1<<start});
    dp[start][start][1<<start] = 0;
    while (!pq.empty()) {
        qd now = pq.top(); pq.pop();
        int px = now.px, rx = now.rx, mt = -now.mt, pt = -now.pt, rt = -now.rt,  vis = now.vis;
        for(int i=0; i<n; i++) {
            int nvis = vis^(1<<i);
            if (dp[px][rx][vis] > dp[px][rx][nvis]) continue;
        }
        if (dp[px][rx][vis] < mt) continue;

        for(auto i: g[px]) {
            int nxt = i.first;
            int nt = pt+i.second*pv;
            int nvis = vis^(1<<nxt);
            int nmt = max(nt, mt);
            if (dp[nxt][rx][nvis]>nmt) {
                dp[nxt][rx][nvis] = nmt;
                pq.push({-nmt, -nt, -rt, nxt, rx, nvis});
            }
        }
        for(auto i: g[rx]) {
            int nxt = i.first;
            int nt = rt+i.second*rv;
            int nvis = vis^(1<<nxt);
            int nmt = max(nt, mt);
            if (dp[px][nxt][nvis]>nmt) {
                dp[px][nxt][nvis] = max(mt, nt);
                pq.push({-nmt, -pt, -nt, px, nxt, nvis});
            }
        }
        if (px==rx) {
            for(auto i: g[px]) {
                int nxt = i.first;
                int nt = mt+i.second*pv;
                int nvis = vis^(1<<nxt);
                int nmt = max(mt, nt);
                if (dp[nxt][nxt][nvis]>nmt) {
                    dp[nxt][nxt][nvis] = nmt;
                    pq.push({-nmt, -nmt, -nmt, nxt, nxt, nvis});
                }
            }
        }
    }
    int ans = 1e9;
    for(int i=0;i<n; i++) {
        cout << dp[i][i][(1<<n)-1] << ' ';
        if (dp[i][i][(1<<n)-1]!=-1)  {
            ans = min(ans, dp[i][i][(1<<n)-1]);
        }
    }
    cout << '\n';
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m; cin >> n >> m >> pv >> rv;
    while(m--) {
        int x, y, l; cin >> x >> y >> l;
        g[x-1].push_back({y-1,l});
    }
    for(int i=0; i<n; i++) {
        int t = dijkstra(i);
        answer = min(answer, t);
    }
    cout << answer;
}