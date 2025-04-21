#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    double output = sqrt(N) * 4;

    cout << fixed << setprecision(6) << output << '\n';

    return 0;
}