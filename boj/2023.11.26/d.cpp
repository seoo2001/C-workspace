#include <bits/stdc++.h>
using namespace std;

int n1, n2;
int arr1[111], arr2[111];
pair<int, int> tmp[111];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n1;
    for (int i=0; i<n1; i++) {
        cin >> arr1[i];
        tmp[i] = {-arr1[i], i};
    }

    cin >> n2;
    for (int i=0; i<n2; i++) cin >> arr2[i];

    sort(tmp, tmp+n1);
    int idx1 = 0, idx2 = 0;
    int ans = 0;
    vector<int> out;
    for (int i=0; i<n1; i++) {
        if (tmp[i].second < idx1) continue;
        
        for (int j=idx2; j<n2; j++) {
            
            if (-tmp[i].first==arr2[j]) {
                idx1 = tmp[i].second;
                idx2 = j+1;
                ans += 1;
                out.push_back(-tmp[i].first);
                break;
            }
        }
    }
    cout << ans << '\n';
    for(int i=0; i<out.size(); i++) {
        cout << out[i] << ' ';
    }
}