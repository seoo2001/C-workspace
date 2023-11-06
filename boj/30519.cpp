#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1000005][3][3];
ll mod = 1000000007;
int atoi(char c) {
    if(c=='P') return 0;
    if(c=='S') return 1;
    if(c=='R') return 2;
}
int win(int l, int s) {
    if(l==s) return 0;
    if((l+1)%3==s) return 2; // s win
    return 1; // l win
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    char ls; cin >> ls;
    string s; cin >> s;
    int n = s.length();

    for(int i=0; i<n; i++) {
        int ai = atoi(s[i]);
        int w = win(atoi(ls), ai);
        dp[i][ai][w] = 1;
        if(i==0) continue;
        for(int j=0; j<3; j++) {
            w = win(j, ai);
            if (w==0) dp[i][ai][w] += dp[i-1][j][2]+dp[i-1][j][0];
            else dp[i][ai][w] += dp[i-1][j][2]+dp[i-1][j][1]+dp[i-1][j][0];

            for(int k=0; k<3; k++) dp[i][j][k] =(dp[i][j][k] + dp[i-1][j][k])%mod;
        }

    }
    ll ans=0;
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) ans += dp[n-1][i][j];
    ans %= mod;
    cout << ans;
    return 0;
}