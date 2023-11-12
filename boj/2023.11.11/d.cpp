#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[1005][1005];
int chk[1005][1005];
int h, w;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans[1005][1005];
int result = 0;

void bfs(int x, int y) {
    pair<int, int> s[10005];
    s[1] = {x, y};
    int top = 1;
    while(top!=0) {
        pair<int, int> now = s[top--];
        if (chk[now.second][now.first]) continue;
        chk[now.second][now.first] = 1;
        for (int i=0; i<4; i++) {
            int nx = now.first+dx[i], ny = now.second+dy[i];
            if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if (board[now.second][now.first]>board[ny][nx]) continue;
            if (chk[ny][nx]==0) s[++top] = {nx,ny};
        }
    }
}


int main() {
    cin >> n >> m;
    cin >> h >> w;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> y >> x;
        if (chk[y-1][x-1]==0) bfs(x-1, y-1);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (chk[i][j]==0) {
                for (int k=0; k<h; k++) {
                    if (i<k) break;
                    if (ans[i-k][j]==1) break;
                    ans[i-k][j] = 1;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (chk[i][j]==0) {
                for (int k=0; k<w; k++) {
                    if (j<k) break;
                    if (ans[i][j-k]==2) break;
                    ans[i][j-k] = 2;
                }
            }
        }
    }

    for(int i=0; i<n-h+1; i++) {
        for(int j=0; j<m-w+1; j++) {
            if (ans[i][j]==0) result += 1;
        }
    }
    cout << result;
}