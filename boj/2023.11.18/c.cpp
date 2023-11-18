#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[55][55];
int b[55][55];
int vst[55][55];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int, int>> s;

void dfs(int x, int y) {
    if (vst[y][x]) return;
    vst[y][x] = 1;
    s.push_back({x,y});
    for (int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if (vst[ny][nx]) continue;
        if (a[y][x]==a[ny][nx]) dfs(nx, ny);
    }
}


int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<m; j++) {
            a[i][j] = s[j];
        }
    }
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<m; j++) {
            b[i][j] = s[j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            s.resize(0);
            dfs(j, i);
            if (s.empty()) continue;
            int t = b[s[0].second][s[0].first];    
            for (int k=0; k<s.size(); k++) {
                if (t!=b[s[k].second][s[k].first]) {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
}