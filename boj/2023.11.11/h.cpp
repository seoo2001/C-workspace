#include <bits/stdc++.h>
using namespace std;

int n, m;
int h, w;
int arr[1010][1010];
int vst[1010][1010];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int x, int y) {
    if (vst[y][x]) return;
    vst[y][x] = 1;
    for(int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if (vst[ny][nx]==0 && arr[ny][nx]>=arr[y][x]) dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    cin >> h >> w;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> arr[i][j];
    }
    int k; cin >> k;
    while(k--) {
        int r, c; cin >> r >> c;
        dfs(c-1, r-1);
    }
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) vst[i][j] = !vst[i][j];

    for(int i=0; i<n; i++) {
        for(int j=1; j<m; j++) {
            for (int k=1; k<w; k++) {
                if (j<k) break;
                if (vst[i][j-k]) break;
                vst[i][j-k] += vst[i][j];
            }
        }
    }
    for(int j=0; j<m; j++) {
        for(int i=1; i<n; i++) {
            for (int k=1; k<h; k++) {
                if (i<k) break;
                if (vst[i-k][j]) break;
                vst[i-k][j] += vst[i][j];
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n-h+1; i++) {
        for(int j=0; j<m-w+1; j++) if(vst[i][j]==0) ans++;
    }
    cout << ans;
}