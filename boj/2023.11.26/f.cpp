#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll k;
struct Edge {
    int s, e, l, r, idx;

};
vector<Edge> v;
int par[101010];
ll rm[202020];
bool vst[202020];

bool comp(Edge &a, Edge &b) {
    return a.r!=b.r ? a.r<b.r : a.l<b.l; 
}
int find(int v) {
    if(v==par[v]) return v;
    return par[v] = find(par[v]);
}

int merge(int u, int v) {
    u = find(u), v = find(v);
    if (u==v) return 0;
    par[u] = v;
    return 1;
}
ll ret = 0;
int mst(ll maxk) {
    int cnt = 0;
    ret = 0;
    ll pp = 0; 
    for(int i=0; i<=n; i++) {
        par[i] = i;
        rm[i] = 0;
    }

    for(int i=0; i<v.size(); i++) {
        if(merge(v[i].s, v[i].e)) {
            if (v[i].l<=maxk) {
                ll t = min((ll)v[i].r, maxk);
                ret+=t;
                rm[v[i].idx] = t-v[i].l;
                pp += t-v[i].l;
                cnt++;
            }
        }
        if(cnt == n-1) break;
    }
    // cout << ret << ' ' << k << ' ' << ret-pp << '\n';
    if (cnt != n-1) return 0;

    if (k<=ret && k>=ret-pp) {
        return 2;
    } else if (k>ret) {
        return 1;
    } 
    return 1;
}

ll bserach() {
    ll left = 0, right = 1e10;
    while(left<=right) {
        // cout << left << ' ' << right << '\n';
        ll mid = (left+right)/2;
        int chk = mst(mid);
        if (chk==2) {
            return mid;
        }
        else if (chk==1) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> k;

    for (int i=0; i<m; i++) {
        int s, e, l, r;
        cin >> s >> e >> l >> r;
        v.push_back({s, e, l, r, i});
    }
    sort(v.begin(), v.end(), comp);
    ll ans = bserach();

    if (ans==-1) {
        cout << "NO";
        return 0;
    } else {
        cout << "YES\n";
        ll pp = ret-k;
        ll ans[202020];
        for (int i=0; i<v.size(); i++) {
            ans[v[i].idx] = v[i].r-min(pp, rm[v[i].idx]);
            pp -= min(pp, rm[v[i].idx]);
        }
        for(int i=0; i<v.size(); i++) {
            cout << ans[i] << '\n';
        }
    }
}