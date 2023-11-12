#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<int, int> weed[100100];
int chk[100100];
map<pair<int,int>,int> m;

int dx[8] = {0,-1,0,1,1,1,-1,-1};
int dy[8] = {1,0,-1,0,1,-1,1,-1};

int bfs(int idx) {
    int d = 2*1e9;
    stack<int> s;
    s.push(idx);
    while (!s.empty()) {
        int nowIdx = s.top(); s.pop();
        if (chk[nowIdx]) continue;
        chk[nowIdx] = 1;
        int x = weed[nowIdx].first, y = weed[nowIdx].second;
        d = min(d, abs(x)+abs(y));
        for(int i=0; i<8; i++) {
            int nxtIdx = m[{x+dx[i], y+dy[i]}];
            if (!nxtIdx) continue;
            if (chk[nxtIdx]) continue;
            s.push(nxtIdx);
        }
    }
    return d;
}

ll ans = 0;
ll maxA = 0;
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x, y; cin >> x >> y;
        weed[i] = {x, y};
        m[{x,y}] = i;
    }

    for(int i=1; i<=n; i++) {
        if (chk[i]==0) {
            ll a = bfs(i);
            maxA = max(maxA, a);
            ans += a;
        }
    }
    cout << ans*2-maxA;
}