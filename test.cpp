#include <bits/stdc++.h>
using namespace std;

int r, c;
int sx, sy;
int g[5][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
}