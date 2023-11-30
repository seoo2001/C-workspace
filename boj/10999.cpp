#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
ll tmul[1000010];
ll tadd[1000010];

void update(int idx, ll mul, ll add) {
    while(idx>=1 && idx<=n) {
        tmul[idx] += mul;
        tadd[idx] += add;
        idx += (idx&-idx);
    }
}

void update_section(int s, int e, ll val) {
    update(s, val, -(s-1)*val);
    update(e+1, -val, val*e);
}

ll sum(int idx) {
    int i = idx;
    ll mm = 0, aa = 0;
    while(i>=1) {
        mm += tmul[i];
        aa += tadd[i];
        i -= (i&-i);
    }

    return mm*idx+aa;
}

ll query(int s, int e) {
    return sum(e) - sum(s-1);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        ll x; cin >> x;
        update_section(i, i, x);
    }
    m = m+k;
    while(m--) {
        int q; cin >> q;
        if (q==1) {
            ll a, b, c; cin >> a >> b >> c;
            update_section(a, b, c);
        } else {
            ll a, b; cin >> a >> b;
            cout << query(a, b) << '\n';
        }
    }
    return 0;
}