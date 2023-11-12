#include <bits/stdc++.h>
using namespace std;

int pl[1005], ml[10005];

int main() {
    int n, m; cin >> n >> m;
    while(m--) {
        int idx, b; char q; cin >> idx >> q >> b;
        if (q=='P') pl[idx] = b+1;
        else ml[idx] = b+1;
    }
    int a1=0, a2=0;
    for(int i=1; i<=n; i++) {
        if (pl[i]==2 && ml[i]==1) a1++;
        if (pl[i]!=1 && ml[i]!=2) a2++;
    }
    cout << a1 << ' ' << a2;
}