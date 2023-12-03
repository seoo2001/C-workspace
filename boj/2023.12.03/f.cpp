#include <bits/stdc++.h>
using namespace std;

int n;


int main() {
    cin >> n;
    int now = 0;
    for(int i=0; i<n; i++) {
        int p, c; cin >> p >> c;
        if (abs(p-now)<=c) {
            now += 1;
        }
    }
    cout << now;
}