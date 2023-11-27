#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s[200200];
bool ch[200200];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ll ss = 0;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        ss += s[i];
    }
    cout << ss <<'\n';
    int m; cin >> m;
    while(m--) {
        int q; cin >> q;
        if (q==1) {
            int idx; ll v; cin >> idx >> v;
            if (!ch[idx]) {
            ss -= s[idx];
            ss += v;
            }
            s[idx] = v;
            cout << ss << '\n';
        } else {
            int idx; cin >> idx;
            if (ch[idx]) ss += s[idx];
            else ss -= s[idx];
            ch[idx] = !ch[idx];
            cout << ss << '\n';
        }
    }
}