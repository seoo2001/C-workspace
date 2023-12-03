#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll k;
char ans;
int main() {
    cin >> k;
    int numlen = 1;
    while(true) {
        ll plen = numlen * 9 * pow(10, (numlen-1)/2);
        if (k>plen) k -= plen;
        else {
            ll numPos = (k-1) / numlen;
            ll idx = (k-1) % numlen;
            if (numlen/2<=idx) idx = numlen - idx - 1;
            ll num = pow(10, (numlen-1)/2) + numPos;
            string s = to_string(num);

            ans = s[idx];
            break;
        }
        numlen++;
    }
    cout << ans << '\n';
}