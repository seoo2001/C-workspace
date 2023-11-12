#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100100];
struct TimeD {
    int s, e;
    int cost = 0;
    TimeD(int s=0, int e=0): s(s), e(e) {}
    bool operator < (const TimeD &t) {
        return s==t.s ? e<t.e : s<t.s;
    }
};

TimeD tl[100100];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        int t; cin >> t;
        tl[i] = {arr[i]-t, arr[i]};
    }
    for(int i=0; i<n; i++) {
        cin >> tl[i].cost;
    }

    sort(tl, tl+n);
    
    int ans = 0;


    for(int i=0; i<n; i++) {
        ans = max(ans, arr[i]);
    }
}