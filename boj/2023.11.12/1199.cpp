#include <bits/stdc++.h>
using namespace std;
int n;
int g[1010][1010];
bool chk() {
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for (int j=1; j<=n; j++) {
            cnt+=g[i][j];
        }
        if (cnt%2==1) return 0;
    }
    return 1;
}
void dfs(int now){
	for(int nxt=1; nxt<=n; nxt++){
		if(g[now][nxt] > 0){
			g[now][nxt]--;
			g[nxt][now]--;
			dfs(nxt);
		}
	}
	cout << now << ' ';
}

void solve() {
    if (!chk()) {
        cout << -1;
        return;
    }
    dfs(1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> g[i][j];
        }
    }
    solve();
}