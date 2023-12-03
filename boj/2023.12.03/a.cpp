#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        for(int i=0; i<x/5; i++) {
            cout << "++++ ";
        }
        for(int i=0; i<x%5; i++) {
            cout << '|';
        }
        cout << '\n';
    }
}