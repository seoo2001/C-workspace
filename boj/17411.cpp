// segtree LIS
// 좌표 압축 -> {LIS 길이, LIS 개수} 로 segtree query, update 반복
// seg[1].x seg[1].y 출력

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;

int mod = 1e9 + 7;
int n;
pair<int, int> tree[4000001];
vector<int> v;
vector<int> comp;

pii f(pii a, pii b) {
    if (a.x > b.x) return a;
    else if (a.x < b.x) return b;
    else return {a.x, (a.y+b.y)%mod};
}

void update(int s, int e, int nd, int idx, int len, int val) {
    if(s>idx || e<idx) return;
    tree[nd] = f(tree[nd], {len, val});
    if (s==e) return;
    update(s, s+e>>1, nd*2, idx, len, val);
    update((s+e>>1)+1, e, nd*2+1, idx, len, val);
}

pii query(int s, int e, int nd, int lo, int hi) {
    if (e<lo || hi<s) return {0, 0};
    if (lo<=s && e<=hi) return tree[nd];
    pii left = query(s, s+e>>1, nd*2, lo, hi);
    pii right = query((s+e>>1)+1, e, nd*2+1, lo, hi);
    return f(left, right);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    v.resize(n+1);
    for(int i=0;i<n; i++) {
        cin >> v[i];
        comp.push_back(v[i]);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int sz = comp.size();
    for(int i=0; i<n; i++) {
        v[i] = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin() + 1;
    }

    for(int i=0; i<n; i++) {
        pii a = query(1, sz, 1, 1, v[i]-1);
        update(1, sz, 1, v[i], a.x+1, max(a.y, 1));
    }
    cout << tree[1].x << ' ' << tree[1].y;
}