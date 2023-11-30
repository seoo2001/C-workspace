#include <bits/stdc++.h>
using namespace std;

int dp[1010];
int rdp[1010];
int arr[1010];
int n;
vector<int> v;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if (arr[i]>arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i=n-1; i>=0; i--) {
        rdp[i] = 1;
        for(int j=n-1; j>i; j--) {
            if (arr[i] > arr[j]) {
                rdp[i] = max(rdp[i], rdp[j]+1);
            }
        } 
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i]+rdp[i]-1);
    }
    cout << ans;

}