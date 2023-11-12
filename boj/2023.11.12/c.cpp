#include <bits/stdc++.h>
using namespace std;

int n;
int arr0[305];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        int v; cin >> v; 
        arr0[i] = v;
    }
    
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        int t = l;
        for(int i=1; i<=n; i++) {
            if (arr0[i]<l || arr0[i]>r) {
                cout << arr0[i] << ' ';
            } else {
                cout << t << ' ';
                t++;
            }
        }
        cout << '\n';
    }
}