#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sqrtN;
struct Query {
    int idx, s, e;
    bool operator < (Query &x) {
        if (s/sqrtN != x.s/sqrtN) return  s/sqrtN < x.s/sqrtN;
        return e < x.e;
    }
};
vector<Query> query;
int ans[500500];
int dp[500500];
vector<ll> v;
vector<ll> comp;
ll res = 0;

void inc(int val) {
    if(val==2) res++;
    if(val==3) res--;
}

void red(int val) {
    if(val==2) res--; 
    if(val==3) res++;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; sqrtN = sqrt(n);
    v.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        comp.push_back(v[i]);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for(int i=1; i<=n; i++) {
        auto idx = lower_bound(comp.begin(), comp.end(), v[i]);
        v[i] = idx - comp.begin() + 1;
    }
    for(int i=0; i<q; i++) {
        int s, e; cin >> s >> e;
        query.push_back({i, s, e});
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for(int i=s; i<=e; i++) inc(++dp[v[i]]);

    ans[query[0].idx] = res;
    for(int i=1; i<q; i++) {
        while(s < query[i].s) { red(dp[v[s]]--); s++; }
        while(s > query[i].s) { s--; inc(++dp[v[s]]); }
        while(e < query[i].e) { e++; inc(++dp[v[e]]); }
        while(e > query[i].e) { red(dp[v[e]]--); e--; }
        ans[query[i].idx] = res;
    }
    for(int i=0; i<q; i++) cout << ans[i] << "\n";
}