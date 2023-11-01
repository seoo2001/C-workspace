#include <bits/stdc++.h>
using namespace std;

int r, c;
int sx, sy;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q;

int bfs(int g[][51]) {
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int val = g[p.second][p.first];
        for(int i=0; i<4; i++) {
            int nx = p.first+dx[i];
            int ny = p.second+dy[i];
            if (nx<0 || nx>=c || ny<0 || ny>=r) continue;
            if (g[ny][nx]==3 && val>=10) return val-9;
            
            if (val >= 10) {
                if (g[ny][nx]==0) {
                    g[ny][nx] = val+1;
                    pair<int, int> a(nx,ny);
                    q.push(a);
                }
            }
            else {
                if (g[ny][nx] != 3 && g[ny][nx] != 2 && g[ny][nx] != 1) {
                    g[ny][nx] = 2;
                    pair<int, int> a(nx,ny);
                    q.push(a);
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int g[51][51];
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        string k;
        cin >> k;
        for (int j=0; j<c; j++) {
            if (k[j]=='X') g[i][j] = 1;
            else if (k[j]=='*') g[i][j] = 2;
            else if (k[j]=='D') g[i][j] = 3;
            else if (k[j]=='S') g[i][j] = 10;
            else g[i][j] = 0;
            if (k[j]=='S') sx = j, sy = i;
        }
    }
    pair<int, int> p = make_pair(sx, sy);
    q.push(p);

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (g[i][j]==2) {
                pair<int, int> p = make_pair(j, i);
                q.push(p);
            }
        }
    }

    int ans = bfs(g);
    if (ans) cout << ans;
    else cout << "KAKTUS";
}