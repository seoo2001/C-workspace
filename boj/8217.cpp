#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> cIdx[300010];
int t[300010];
int l[300010], r[300010];
vector<int> v[300010];
tuple<int, int, ll> qd[300010];
ll tree[300010];
int q;

void update(int idx, ll v) {
    while(idx<=m) {
        tree[idx] += v;
        idx += (idx&-idx);
    }
}
ll sum(int idx) {
    ll s = 0;
    while(idx>0) {
        s += tree[idx];
        idx -= (idx&-idx);
    }
    return s;
}

void f(int day) {
    int s, e; ll w;
    tie(s, e, w) = qd[day];
    if (s>e) {
        update(1, w); update(e+1, -w);
        update(s, w);
    } else {
        update(s, w); update(e+1, -w);
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int idx; cin >> idx;
        cIdx[idx].push_back(i);
    }
    for(int i=1; i<=n; i++) {
        cin >> t[i];
    }
    cin >> q;
    for(int i=1; i<=q; i++) {
        int s, e; ll w; cin >> s >> e >> w;
        qd[i] = make_tuple(s, e, w);
    }
    for(int i=1; i<=n; i++) l[i] = 1, r[i] = q+1;

    while(1) {
        for(int i=1; i<=q+1; i++) v[i].clear();
        bool chk = false;
        for(int i=1; i<=n; i++) {
            if (l[i]<r[i]) {
                chk = true;
                v[(l[i]+r[i])/2].push_back(i);
            }
        }
        if (!chk) break;

        memset(tree, 0, sizeof(tree));
        for (int day=1; day<=q; day++) {
            f(day);
            for (auto idx : v[day]) {
                ll ss = 0;
                for (auto x : cIdx[idx]) {
                    ss += sum(x);
                    if (ss>=t[idx]) break;
                }
                if (t[idx]<=ss) {
                    r[idx] = day;
                } else {
                    l[idx] = day+1;
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if (l[i] > q) cout << "NIE" << '\n';
        else cout << l[i] << '\n';
    }
    return 0;
}