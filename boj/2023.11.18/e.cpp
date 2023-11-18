#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<pair<int, int>> vt;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i = 1, j = 1;
    while(i*j<=1e9+1e8) {
        v.push_back(i*j);
        vt.push_back({i ,j});
        if (i==j) i++;
        else j++;
    }
    int t; cin >> t;
    while(t--) {
        cin >> n;
        int idx = lower_bound(v.begin(), v.end(), n) - v.begin();
        cout << (vt[idx].first+vt[idx].second)*2 << '\n';
    }
}