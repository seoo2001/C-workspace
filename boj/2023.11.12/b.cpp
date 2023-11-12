#include <bits/stdc++.h>
using namespace std;
deque<int> dq;

int main() {
    int n; cin >> n;
    for(int i=n; i>=1; i--) {
        if (i%2) dq.push_back(i);
        else dq.push_front(i);    
    }
    for(int i=0; i<n; i++) {
        cout << dq.front() << ' '; dq.pop_front();
    }
}