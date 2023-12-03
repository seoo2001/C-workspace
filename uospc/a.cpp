#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    long long ans = 1;
    ans = ans * n * (n-1) * (n-2) * (n-3) * (n-4);
    ans = ans / (5*4*3*2);
    cout << ans;
}