#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int xx = 1001, yy = 1001;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (y < yy) {
            yy = y;
            xx = x;
        }
    }
    cout << xx << ' ' << yy;
}