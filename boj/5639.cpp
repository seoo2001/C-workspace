#include <bits/stdc++.h>
using namespace std;

int arr[10101];

void order(int s, int e) {
    if(s>=e) return;
    if (s==e-1) {
        cout << arr[s] << '\n';
        return ;
    }
    int idx = s+1;
    while (idx<e) {
        if (arr[s]<arr[idx]) break;
        idx++;
    }
    order(s+1, idx);
    order(idx, e);
    cout << arr[s] << '\n';
}

int main() {
    int n; int i = 0;
    while (cin >> n) arr[i++] = n;
    order(0, i);
}