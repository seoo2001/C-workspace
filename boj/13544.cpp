#include <bits/stdc++.h>
using namespace std;

vector<int> tree[400000];
int arr[101010];
int n;

void update(int s, int e, int node, int index, int val) {
    if (s> index || e<index) return;
    tree[node].push_back(val);
    if (s==e) return;
    update(s, s+e>>1, node*2, index, val);
    update((s+e>>1)+1, e, node*2+1, index, val);    
}

int bSearch(int idx, int d) {
    return tree[idx].end() - upper_bound(tree[idx].begin(), tree[idx].end(), d);
}

int query(int s, int e, int node, int left, int right, int d) {
    if (e<left || s>right) return 0;
    if (left<=s && e<=right) {
        return bSearch(node, d);
    }
    return query(s, s+e>>1, node*2, left, right, d) + query((s+e>>1)+1, e, node*2+1, left, right, d);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int m; cin >> m;
        update(1, n, 1, i, m);
    }
    for(int i=1; i<400000; i++) {
        sort(tree[i].begin(), tree[i].end());
    }
    int q; cin >> q;
    int ans = 0;
    while(q--) {
        int a, b, c; cin >> a >> b >> c;
        a ^= ans; b ^= ans; c ^= ans;
        ans = query(1, n, 1, a, b, c);
        cout << ans << '\n';
    }
}  