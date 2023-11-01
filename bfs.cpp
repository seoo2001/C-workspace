#include <bits/stdc++.h>

using namespace std;

int board[52][52];
bool vis[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    vis[0][0] =  1;
    Q.push({0,0});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            cout << nx << ' ' << ny << '\n';
            if (nx < 0 || nx >= 50 || ny < 0 || ny >= 50) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}