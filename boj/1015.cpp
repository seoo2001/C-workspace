#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    int ns[N];
    for(int i=0; i<N; i++) {
        ns[v[i].second] = i;
    }    
    for (int i =0; i<N; i++) cout << ns[i] << ' ';
}