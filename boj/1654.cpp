#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n;
ll maxl;
ll arr[10101];

ll f(int x) {
    ll a = 0;
    for(int i=0; i<m; i++) {
        a += arr[i]/x; 
    }
    return a;
}

ll bserach() {
    ll s = 1, e = maxl;
    while(s<=e) {
        ll mid = (s+e)/2;
        
        if (f(mid)>=n) s = mid+1;
        else e = mid-1;
    }
    return e;
}

int main() {
    cin >> m >> n;
    
    for(int i=0; i<m; i++) {
        cin >> arr[i];
        maxl = max(maxl, arr[i]);
    }
    cout << bserach();
}