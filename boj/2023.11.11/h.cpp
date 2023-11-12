#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sqrtN;

vector<ll> v;
vector<ll> comp;
ll res = 0;
map<ll, int> compMap;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    v.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        comp.push_back(v[i]);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for(int i=1; i<=n; i++) {
        ll temp = v[i];
        auto idx = lower_bound(comp.begin(), comp.end(), v[i]);
        v[i] = idx - comp.begin() + 1;
        compMap[temp] = v[i];
    }

    int q; cin >> q;
    while(q--) {
        int qq; cin >> qq;
        if (qq==1) {
            int ans = 0;
            int l, r, k; cin >> l >> r >> k;
            for(int i=l; i<=r; i++) {
                if (v[i]==compMap[k]) {
                    ans += 1;
                } 
            }
            cout << ans << '\n';
        } else {
            int l, r; cin >> l >> r;
            for(int i=l; i<=r; i++) {
                v[i] = 0;
            }
        }
    }
}