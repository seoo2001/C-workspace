#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[105][105];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int vst[105][105];

void bfs(int x, int y) {
    stack<pair<int, int>> s;
    s.push({x,y});
    while (!s.empty()) {
        pair<int, int> now = s.top(); s.pop();
        if (vst[now.first][now.second]) continue;
        vst[now.first][now.second] = 1;
        for (int i=0; i<4; i++) {
            int nx = now.first+dx[i], ny = now.second+dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (board[nx][ny]) vst[nx][ny] += 1;
            if (board[nx][ny]==0 && vst[nx][ny]==0) s.push({nx,ny});
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> board[i][j];
    }
    int ans = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        memset(vst, 0, sizeof(vst));
        bfs(0,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (board[i][j] && vst[i][j]>=2){
                    board[i][j] = 0;
                    flag = true;
                }
            }
        }
        ans += 1;
    }
    cout << ans-1;
}