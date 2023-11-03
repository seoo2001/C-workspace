#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

// lazy seg tree, 구간 합 쿼리, 구간 값 변경 쿼리

ll init(vll &arr, vll &tree, int node, int start, int end) {
    if(start==end) {
        return tree[node] = arr[start];
    }
    int mid = (start+end)/2;
    return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1, mid+1, end);
}

void update_lazy(vll &tree, vll &lazy, int node, int start, int end) {
    if(lazy[node] != 0) {
        tree[node] += (end-start+1) * lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vll &tree, vll &lazy, int node, int start, int end, int left, int right, ll diff) {
    update_lazy(tree, lazy, node, start, end);
    if(left>end || right<start) {
        return;
    }
    if(left<=start && end<=right) {
        tree[node] += (end-start+1) *diff;
        if(start!=end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    int mid = (start+end)/2;
    update_range(tree, lazy, node*2, start, mid, left, right, diff);
    update_range(tree, lazy, node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2]+tree[node*2+1];

}

ll sum(vll &tree, vll &lazy, int node, int start, int end, int left, int right){
    update_lazy(tree, lazy, node, start, end);
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    return sum(tree, lazy, node*2, start, (start+end)/2, left, right) + sum(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    return 0;
}