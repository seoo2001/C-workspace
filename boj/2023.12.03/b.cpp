#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> tlii;
int n, m, k;

ll dp[505][505];
vector<tlii> gh[505];

void dijkstra() {
    memset(dp, -1, sizeof(dp));
    priority_queue<tlii> pq;
    pq.push({0, 1, k});
    while(!pq.empty()) {
        ll time; int now, cnt; 
        tie(time, now, cnt) = pq.top(); pq.pop();
        time *= -1;
        // cout << now << ' ' << ' ' << time << '\n';
        if (dp[now][cnt]!=-1 && dp[now][cnt] < time) continue;
        dp[now][cnt] = time;

        for (auto i: gh[now]) {
            ll dt; int next, dg;
            tie(dt, next, dg) = i;
            ll nt = dg*ceil(double(time)/dg);

            // cout << nt << ' ' << now << next << '\n';
            if (cnt!=0 && nt>time) {
                if (dp[next][cnt-1]==-1 || dp[next][cnt-1] > time+dt) {
                    dp[next][cnt-1] = time+dt;
                    pq.push({-(time+dt),next, cnt-1});
                }
            }
            if (dp[next][cnt]==-1 || dp[next][cnt] > nt+dt) {
                dp[next][cnt] = nt+dt;
                pq.push({-(nt+dt),next, cnt});
            }
        }
    } 
}



int main () {
    cin >> n >> m >> k;
    for(int i=0; i<m; i++) {
        int s, e, t, g; cin >> s >> e >> t >> g;
        gh[s].push_back({t, e, g});
    }
    
    dijkstra();

    ll ans = 1e12;
    for(int i=0; i<=k; i++) {
        if (dp[n][i]!= -1) {
            ans = min(ans, dp[n][i]);
        }
    }
    if (ans!=1e12) cout << ans;
    else cout << -1;
}