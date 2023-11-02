#include <bits/stdc++.h>
typedef long long ll;
typedef vector<ll> vll;

using namespace std;

ll tree[405];
// sum seg tree

ll init(vll &arr, vll &tree, int node, int start, int end) {
    if (start==end) {
        return tree[node] = arr[start];
    }
    int mid = (start+end)/2;
    return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1, mid+1, end);
}

ll sum(vll &arr, vll &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start ) return 0;
    if (left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(arr, tree, node*2, start, mid, left, right) + sum(arr, tree, node*2+1, mid+1, end, left, right);
}

void update(vll &arr, vll &tree, int node, int start, int end, int idx, ll diff) {
    if (idx<start || idx>end) return ;
    tree[node] += diff;
    if (start != end) {
        int mid = (start+end)/2;
        update(arr, tree, node*2, start, mid, idx, diff);
        update(arr, tree, node*2+1, mid+1, end, idx, diff);
    }
}

int main() {

}