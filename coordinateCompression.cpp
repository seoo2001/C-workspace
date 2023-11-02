#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
vector<ll> v;
vector<ll> comp;

// 좌표압축
int main() {
    cin >> n;
    v.resize(n+1);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        comp.push_back(v[i]);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for(int i=0; i<n; i++) {
        auto idx = lower_bound(comp.begin(), comp.end(), v[i]);
        v[i] = idx - comp.begin() + 1;
    }
}