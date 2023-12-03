#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x; cin >> x;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=1; j<=n; j++) {
            cout << (j%(min(n, 2)))+1 << ' ';
        }
        cout << '\n';
    }
}