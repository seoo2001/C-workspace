#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;

int n, m, k;

ll dp[10101][22];

vector<pair<int, int>> g[10101];

int main() {
    cin >> n >> m >> k;
    
    for(int i=1; i<=n; i++) {
        fill_n(dp[i], k+1, 1e10+10);
    }
    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    priority_queue<tuple<ll, int, int>> pq;
    pq.push(make_tuple(0, 1, k));
    while (!pq.empty()) {
        ll dist; int now, kl;
        tie(dist, now, kl) = pq.top(); pq.pop();
        dist *= -1;
        if (dp[now][kl] < dist) continue;
        dp[now][kl] = dist;
        for(auto i : g[now]) {
            int next = i.x;
            ll nd = dist + i.y;
            if (nd<dp[next][kl]) {
                pq.push(make_tuple(-nd, next, kl));
                dp[next][kl] = nd;
            }
            if (kl>=1) {
                if (dist<dp[next][kl-1]) {
                    pq.push(make_tuple(-dist, next, kl-1));
                    dp[next][kl-1] = dist;
                }
            }
        }
    }
    ll ans = 1e10+10;
    for (int i=0; i<=k; i++) ans = min(ans, dp[n][i]);
    cout << ans;
}