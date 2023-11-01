#include <bits/stdc++.h>
#define N 1000
using namespace std;

vector<int> g[N+1];
stack<int> s;
vector<bool> visited(N+1);

void dfs(int v) {
    visited[v] = 1;
    for (int i=0; i<g[v].size(); i++) {
        if (!visited[g[v][i]]) dfs(i);
    }
    s.push(v);
}

int main() {

}