#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll tree[2000200];
int arr[1000100];

ll sum(int start, int end, int node, int left, int right) {
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int idx) {
    if(end<idx || idx<start) return;
    tree[node] += 1;
    if(start!=end) {
        int mid = (start+end)/2;
        update(start, mid, node*2, idx);
        update(mid+1, end, node*2+1, idx);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        int num; cin >> num;
        arr[num] = i;
    }
    ll ans = 0;
    for(int i=0; i<n; i++) {
        int num; cin >> num;
        int idx = arr[num];
        ans += sum(0, n-1, 1, idx, n-1);
        update(0, n-1, 1, idx);
    }
    cout << ans;
}