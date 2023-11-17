#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[100100];
int d[100100];
ll c[100100];

struct TimeD {
    int s, e;
    ll cost = 0;
    TimeD(int s=0, int e=0): s(s), e(e) {}
    bool operator < (const TimeD &t) {
        return e==t.e ? s>t.s : e<t.e;
    }
};
TimeD tl[100100];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) {
        int t; cin >> t;
        tl[i] = {arr[i]-t, arr[i]};
    }
    for(int i=0; i<n; i++) cin >> tl[i].cost;

    sort(tl, tl+n);
    d[0] = -1;
    for(int i=0; i<n; i++) {
        d[i+1] = tl[i].e;
    }
    c[0] = 0;
    for(int i=0; i<n; i++) {
        int idx = lower_bound(d, d+i+1, tl[i].s)-d;
        if (d[idx]>=tl[i].s && idx!=0) idx--;
        c[i+1] = max(c[i], tl[i].cost+c[idx]);;
    }
    cout << c[n];
}