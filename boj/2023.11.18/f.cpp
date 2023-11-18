#include <bits/stdc++.h>
using namespace std;
int n, m;

int tree[2000000];
bool lazy[2000000];

int init(int start, int end, int node) {
    if (start==end) return tree[node] = 1;
    int mid = (start+end)/2;
    tree[node] = init(start, mid, node*2)+init(mid+1, end, node*2+1);
    return tree[node];
}


void lazy_update(int start, int end, int node) {
    if(lazy[node]) {
        tree[node] = 0;
        if(start!=end) {
            lazy[node*2] = 1;
            lazy[node*2+1] = 1;
        }
        lazy[node] = 0;
    }
}

void update_range(int start, int end, int node, int left, int right) {
    lazy_update(start, end, node);
    if (tree[node]==0) return ;
    if(right<start || end<left) return ;
    if(left<=start && end<=right) {
        tree[node] = 0;
        if(start!=end) {
            lazy[node*2] = 1;
            lazy[node*2+1] = 1;
        }
        return ;
    }
    int mid = (start+end)/2;
    update_range(start,mid,node*2,left,right);
    update_range(mid+1,end,node*2+1,left,right);
    tree[node] = tree[node*2]+tree[node*2+1];
}

int sum(int start, int end, int node, int left, int right) {
    lazy_update(start, end, node);
    if(right<start || end<left) return 0;
    if(left<=start && end<=right) return tree[node];
    if (tree[node]==0) return 0;
    int mid = (start+end)/2;
    return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int ans = 0;
    int temp  = 0;
    n--;
    init(1, n, 1);
    while(m--) {
        int s, e; cin >> s >> e;
        e--;
        int need = sum(1, n, 1, s, e);
        temp += 1;
        if (need>0) {
            if (need>temp) {
                need -= temp;
                temp = 0;
            } else {
                temp -= need;
                need = 0;
            }
            ans += need;
        }
        update_range(1, n, 1, s, e);
    }
    cout << ans;
}