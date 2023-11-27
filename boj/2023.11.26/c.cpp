#include <bits/stdc++.h>
using namespace std;

int n;
int arr[202020];
int ch[10];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i=1; i<9; i++) {
        for (int j=i+1; j<10; j++) {
            int maxl = 0;
            for (int idx=0; idx<n; idx++) {
                if (arr[idx]==i || arr[idx]==j) {
                    maxl++;
                } else {
                    ans = max(ans, maxl);
                    maxl = 0;
                }
            }
            ans = max(ans, maxl);

        }
    }
    cout << ans;
}