#include <bits/stdc++.h>
using namespace std;

int main() {
    // 띄어쓰기 포함한 문자열 입력
    string a;
    getline(cin, a);
    int result = 1;
    for (int i=0;  i<a.length(); i++) {
        if (a[i]==' ') result++;
    }
    if (a[0]==' ') result --;
    if (a[a.length()-1]==' ') result--;
    cout << result;
}