#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sqrtN;

struct Query{
    int idx, s, e;
    bool operator < (Query &x) {
        if (s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
        return e < x.e;
    }
};

vector<Query> query;
vector<int> v;
ll res = 0;
ll ans[101010];
// mos 구간 합 구하기 O( min(N, Q) * sqrt(N) ) 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; sqrtN = sqrt(n);
    v.resize(n+1);

    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for(int i=0; i<q; i++) {
        int s, e; cin >> s >> e;
        query.push_back({i, s, e});
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for(int i=s; i<=e; i++) {
        res += v[i];
    }
    ans[query[0].idx] = res;
    for(int i=1; i<q; i++) {
        while(s < query[i].s) res -= v[s++];
        while(s > query[i].s) res += v[--s];
        while(e < query[i].e) res += v[++e];
        while(e > query[i].e) res -= v[e--];
        ans[query[i].idx] = res;
    }
    for(int i=0; i<q; i++) cout << ans[i] << "\n";
}