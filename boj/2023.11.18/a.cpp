#include <bits/stdc++.h>
using namespace std;
string s;
char t[5] = {'K', 'O', 'R', 'E', 'A'};
int main() {
    int n = 0;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        if (s[i]==t[n%5]) n++;
    }    
    cout << n;
}