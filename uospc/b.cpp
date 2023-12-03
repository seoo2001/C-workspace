#include <bits/stdc++.h>
using namespace std;

int n;
int k;
char s[500100];

int main() {
    cin >> n >> k;
    for (int i=0; i<n;i++) {
        cin >> s[i];
    }
    for(int i=k-1; i<n; i++) {
        cout << s[i];
    }
    if ((n-k+1)%2==1) {
        for(int i=k-2; i>=0; i--) cout << s[i];
    } else {
        for(int i=0; i<=k-2; i++) {
            cout << s[i];
        }
    }
}