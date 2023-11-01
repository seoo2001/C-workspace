#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> ns;

bool comp(string a, string b) {
    return a.size() < b.size();
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        ns.push_back(s);
    }
    sort(ns.begin(), ns.end());
    stable_sort(ns.begin(), ns.end(), comp);
    ns.erase(unique(ns.begin(), ns.end()), ns.end());
    for(int i=0; i<ns.size(); i++) {
        cout << ns[i] << '\n';
    }
}