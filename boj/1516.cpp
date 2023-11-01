#include <bits/stdc++.h>
using namespace std;

int N;
int t[501];
vector<int> g[501];
vector<int> indegree(501);
int dis[501];
priority_queue<pair<int, int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> t[i];
        int c = 0;
        while(true) {
            cin >> c;
            if (c==-1) break;
            g[c].push_back(i);
            indegree[i]++;
        }
    }
    for(int i=1; i<=N; i++)  {
        if(!indegree[i]) pq.push({i,0}); dis[i] = t[i];
    }
    while(!pq.empty()) {
        pair<int, int> x = pq.top(); pq.pop();
        int here = x.first;
        int d = x.second;
        for(int i=0; i<g[here].size(); i++) {
            int nx = g[here][i];
            indegree[nx]--;
            dis[nx]=max(dis[nx], dis[here]+t[nx]);
            if (!indegree[nx]) pq.push({nx, dis[here]});
        }
    }
    for(int i=1; i<=N; i++) cout << dis[i] << '\n';
}