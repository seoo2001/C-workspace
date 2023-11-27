#include <bits/stdc++.h>
using namespace std;

int par[1010];
int find(int v){
	if(v == par[v]) return v;
	return par[v] = find(par[v]);
}
int merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return 0;
	par[u] = v;
	return 1;
}

struct edge{
	int val;
	int s, e;
	edge(){}
	edge(int x, int y, int z) : val(x), s(y), e(z) {}
};

vector<edge> v;

bool comp(edge &a, edge &b){
	return a.val < b.val;
}

int mst(int n){
	int cnt = 0, ret = 0;
	for(int i=0; i<=n; i++) par[i] = i;

	for(int i=0; i<v.size(); i++){
		if(merge(v[i].s, v[i].e)){
            ret+=v[i].val;
			cnt++;
		}
		if(cnt == n-1) break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
    int n, m, k; cin >> n >> m >> k;

    v.clear();
	for(int i=0; i<m; i++){
		int c; int s, e;
		cin >> c >> s >> e;
		v.push_back({c, s, e});
	}

	int a, b;
	sort(v.begin(), v.end(), comp);
	a = mst(n);
    cout << a;
}