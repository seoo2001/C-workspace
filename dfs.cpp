#include <bits/stdc++.h>

using namespace std;

int n, m, v;
int g[1001][1001];
int vis[1001];
void dfs(int s) {
    vis[s] = 1;
    cout << s << ' ';
    for (int i=1; i<=n; i++) {
        if (!vis[i] && g[s][i]==1) {
            dfs(i);
        }
    }
}

void bfs(int s) {
    int rear= 0, front = 0;
    int q[10001];
    q[rear++] = s;
    vis[s] = 1;
    cout << s << ' ';
    while (rear > front) {
        int x = q[front++];
        for(int i=1; i<=n; i++) {
            if (!vis[i] && g[x][i]==1) {
                cout << i << ' ';
                vis[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    dfs(v);
    fill_n(vis, 1001, 0);
    cout << '\n';
    bfs(v);
}