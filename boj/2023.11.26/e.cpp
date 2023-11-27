#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[1000001];
ll fact[1000005],factInv[1000005],mod = 998244353;
ll mpow(ll x,ll m) {
    if(!m) return 1;
    ll tmp = mpow(x,m/2);
    tmp = tmp*tmp % mod;
    if(m % 2) return tmp*x%mod;
    return tmp;
}
 
ll Com(ll x,ll r) {
    return fact[x]*factInv[r]%mod*factInv[x-r]%mod;
}
 

map<int, int> cntm;
int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for(int i = 1;i <= 1000001;i++) fact[i] = fact[i-1]*i%mod;
    factInv[1000001] = mpow(fact[1000001],mod-2);
    for(int i = 1000000;i >= 0;i--) factInv[i] = factInv[i+1]*(i+1)%mod;

    cin >> n;
    
    for(int i=0; i<n; i++) {
        int m; cin >> m;
        for(int i=0; i<m; i++) {
            int x; cin >> x;
            cntm[x]++;
        }
    }
    for(auto x: cntm) {
        int c = x.second;
        for(int i=1; i<=c; i++) {
            ans[i] = (ans[i] + Com(c, i))%mod;
        }
    }
    for(int i =1; i<=n; i++) cout << ans[i] << '\n';
}