#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll tree;
vll lazy;

void lazy_update(int start, int end, int node) {
    if(lazy[node]) {
        tree[node] = (end-start+1)-tree[node];
        if(start!=end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        lazy[node] = !lazy[node];
    }
}

void update_range(int start, int end, int node, int left, int right) {
    lazy_update(start, end, node);
    if(right<start || end<left) return ;
    if(left<=start && end<=right) {
        tree[node] = (end-start+1)-tree[node];
        if(start!=end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        return ;
    }
    int mid = (start+end)/2;
    update_range(start,mid,node*2,left,right);
    update_range(mid+1,end,node*2+1,left,right);
    tree[node] = tree[node*2]+tree[node*2+1];
}

ll sum(int start, int end, int node, int left, int right) {
    lazy_update(start, end, node);
    if(right<start || end<left) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    tree.resize(n*4+10);
    lazy.resize(n*4+10);

    while(q--) {
        int c, s, e; cin >> c >> s >> e;
        if (c==0) update_range(1, n, 1, s, e);
        else cout << sum(1, n, 1, s, e) << '\n';
    }
    return 0;
}