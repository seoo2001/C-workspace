#include <bits/stdc++.h>
using namespace std;

int t1 = -2, t2 = -2;
int ans = 0;
int main() {
    int n; cin >> n;
    while(n--) {
        int a, b; cin >> a >> b;
        if (t1==a && a!=0) ans+=1; 
        if (t2==b && b!=0) ans+=1;
        if (a==b && a!=0) ans += 1;
        t1 = a;
        t2 = b;
    }
    cout << ans;
}