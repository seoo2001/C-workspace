#include <bits/stdc++.h>
using namespace std;

int n, m;
int tree[1050][1050];
int arr[1050][1050];

void update(int y, int x, int diff) {
    for(int i=y; i<=n; i += (i&-i)) {
        for(int j=x; j<=n; j += (j&-j)) {
            tree[i][j] += diff;
        }
    }
}

int sum(int y, int x) {
    int res = 0;
    for(int i=y; i>=1; i -= (i&-i)) {
        for(int j=x; j>=1; j -= (j&-j)) {
            res+=tree[i][j];
        }
    }
    return res;
}

int query(int y1, int x1, int y2, int x2) {
    return sum(y2,x2)-sum(y2,x1-1)-sum(y1-1,x2)+sum(y1-1,x1-1);
}

int main() {
    cin >> n >> m;
    ios::sync_with_stdio(0); cin.tie(0);

    for (int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }
    
    while(m--) {
        int q; cin >> q;
        if (q==0) {
            int x, y, v; cin >> y >> x >> v;
            int t = v - arr[y][x];
            arr[y][x] = v;
            update(y, x, t);
        } else {
            int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;

            cout << query(y1, x1, y2, x2) << '\n';
        }
    }

    return 0;
}