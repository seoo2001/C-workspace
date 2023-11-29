#include <bits/stdc++.h>
#define MAXS (1<<12)+5
using namespace std;

int n, m;

int temp[1050][MAXS];
int tree[MAXS][MAXS];

int arr[1050][1050];

int initx(int idx, int s, int e, int node) {
    if (s==e) return temp[idx][node] = arr[idx][s];
    int mid = (s+e) >> 1;
    temp[idx][node] = initx(idx, s, mid, node*2) + initx(idx, mid+1, e, node*2+1);
    return temp[idx][node];
}

int init(int idx, int s, int e, int node) {
    if (s==e) return tree[idx][node] = temp[s][idx];
    int mid = (s+e) >> 1;
    tree[idx][node] = init(idx, s, mid, node*2) + init(idx, mid+1, e, node*2+1);
    return tree[idx][node];
}
void updatey(int idx, int s, int e, int node, int index, int diff) {
    if (e<index || s>index) return;
    tree[node][idx] += diff;
    if (s==e) return;
    int mid = (s+e) >> 1;
    updatey(idx, s, mid, node*2, index, diff);
    updatey(idx, mid+1, e, node*2+1, index, diff);
}

void update(int idx, int s, int e, int node, int index, int diff) {
    if (e>index || s<index) return;
    tree[idx][node] += diff;
    updatey(node, 0, n-1, 1, idx, diff);
    if (s==e) return;
    int mid = (s+e) >> 1;
    update(idx, s, mid, node*2, index, diff);
    update(idx, mid+1, e, node*2+1, index, diff);
}


int queryy(int idx, int s, int e, int node, int ly, int ry) {
    if (e<ly || s>ry) return 0;
    if (s<=ly && ry <=e) {
        return tree[idx][node];
    }
    int mid = (s+e) >> 1;
    return queryy(idx, s, mid, node*2, ly, ry) + queryy(idx, mid+1, s, node*2+1, ly, ry);
}
int query(int s, int e, int node, int lx, int rx, int ly, int ry) {
    if (e<lx || s>rx) return 0;
    if (s<=lx && rx <=e) {
        queryy(node, 0, n-1, 1, ly, ry);
    }
    int mid = (s+e) >> 1;
    return query(s, mid, node*2, lx, rx, ly, ry) + query(mid+1, s, node*2+1, lx, rx, ly, ry);
}


int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> arr[i][j];
        initx(i, 0, n-1, 1);
    }
    for (int i=0; i<MAXS; i++) {
        init(i, 0, n-1, 1);
    }
    for(int i=0; i<12; i++) {
        for (int j=0; j<12; j++) {
            cout << tree[i][j] << ' ';
        }
        cout << '\n';
    }

    while(m--) {
        int q; cin >> q;
        if (q==0) {
            int x, y, v; cin >> x >> y >> v;
            x--; y--;
            int t = v - arr[y][x];
            arr[y][x] = v;
            update(x, 0, n-1, 1, y, t);
        } else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            cout << query(0, n-1, 1, x1, x2, y1, y2) << '\n';
        }

    }

    return 0;
}