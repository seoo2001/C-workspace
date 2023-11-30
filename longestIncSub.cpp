#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
int arr[1000100];
int ch[1000100];
int bsearch(int w) {
    return lower_bound(v.begin(), v.end(), w) - v.begin();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int cnt = 1;
    v.push_back(arr[0]);
    ch[0] = 1;
    for(int i=1; i<n; i++) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);
            ch[i] = ++cnt;
        }
        else {
            int idx = bsearch(arr[i]);
            v[idx] = arr[i];
            ch[i] = idx+1;
        }
    }
    cout << cnt << '\n';
    vector<int> ans;
    for(int i=n-1; i>=0; i--) {
        if (ch[i]==cnt) {
            ans.push_back(arr[i]);
            cnt--;
        }
        if (cnt==0) break;
    }    
    for(int i=ans.size()-1; i>=0; i--) {
        cout << ans[i] << ' ';
    }
}