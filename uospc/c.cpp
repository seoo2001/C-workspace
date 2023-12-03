#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int k;
ll n;
set<int> s[3];
int main() {
    int x = 1, y = 1;
    v.push_back(1);
    v.push_back(1);
    while(x+y<=1e16+10) {
        v.push_back(x+y);
        int t = y;
        y = x+y;
        x = t;
    }
    int sz = v.size();
    for(int i=0; i<sz; i++) {
        s[0].insert(v[i]);
        for(int j=0; j<sz; j++) {
            s[1].insert(v[i]+v[j]);
            for(int w=0; w<sz; w++) {
                s[2].insert(v[i]+v[j]+v[w]);
            }
        }
    }
    int q; cin >> q;
    while(q--) {
        cin >> k >> n;
        if (s[k-1].find(n)!=s[k-1].end()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}