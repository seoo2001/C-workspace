#include <bits/stdc++.h>
using namespace std;

int n, p, q;
string s[505], r[505], l[505];
int dp[505][505][505];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p >> q;
    for (int i=1; i<=n; i++) cin >> s[i];
    for (int i=1; i<=p; i++) cin >> r[i];
    for (int i=1; i<=q; i++) cin >> l[i];
    r[0] = "0"; l[0] = "0";
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=p; j++) {
            for (int k=0; k<=q; k++) {
                int temp = 0;
                if (s[i].compare(r[j])==0) temp = max(temp, dp[i-1][j-1][k] + 1);
                if (s[i].compare(l[k])==0) temp = max(temp, dp[i-1][j][k-1] + 1);
                
                dp[i][j][k] = max(max(temp, dp[i-1][j][k]), max(dp[i][j-1][k], dp[i][j][k-1]));
                
            }
        }   
    }
    cout << dp[n][p][q];

    return 0;
}