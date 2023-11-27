#include <bits/stdc++.h>
using namespace std;
int n;
int a[6];
int x, y;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0; i<6; i++) cin >> a[i];
    cin >> x >> y;
    int ans = 0;
    for (int i=0; i<6; i++) {
        ans += a[i]/x;
        if (a[i]%x!=0) ans += 1;
    }
    cout << ans << '\n';
    cout << n/y << ' ' << n%y;
}