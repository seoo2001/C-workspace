#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll d;
vector<int> mon;
vector<ll> itm;
int main() {
    cin >> n >> d;
    for(int i=0; i<n; i++) {
        int x, t; cin >> x >> t;
        if (x==1) mon.push_back(t);
        else itm.push_back(t);
    }
    sort(mon.begin(), mon.end());
    sort(itm.begin(), itm.end());
    int ans = itm.size();
    int idx = 0;
    for(int i=0; i<mon.size(); i++) {
        while (mon[i]>=d && idx<itm.size()) {
            d*=itm[idx++];
        }
        if (mon[i]>=d) break;
        d+=mon[i];
        ans+=1;
    }
    cout << ans;
}