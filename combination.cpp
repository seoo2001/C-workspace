#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for(int i = 1;i <= 1000001;i++) fact[i] = fact[i-1]*i%mod;
    factInv[1000001] = mpow(fact[1000001],mod-2);
    for(int i = 1000000;i >= 0;i--) factInv[i] = factInv[i+1]*(i+1)%mod;

    cout << Com(10, 5);
}