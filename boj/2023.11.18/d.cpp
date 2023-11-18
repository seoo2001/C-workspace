#include <bits/stdc++.h>
using namespace std;
int n;
int src[100100];
int dst[100100];
int dis[100100];
int temp[100100];
int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> src[i];
    for (int i=0; i<n; i++) cin >> dst[i];
    for (int i=0; i<n; i++) cin >> dis[i];

    for (int i=0; i<n; i++) {
        int k = abs(src[i]-dst[i]);
        if (k%dis[i] != 0) {
            cout << -1;
            return 0;
        }
        temp[i] = k / dis[i];
    }
    int maxd = 0;
    for(int i=0; i<n; i++) {
        if (i!=0 && maxd%2 != temp[i]%2) {
            cout << -1; return 0;
        }
        maxd = max(maxd, temp[i]);
    }
    cout << maxd;
}