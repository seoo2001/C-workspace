#include <bits/stdc++.h>
using namespace std;
int n; 
int arr[105];
int main() {
    cin >> n;
    int k = n;
    int i = 0;
    while (i<100) {
        cout << "? ";
        for(int j=100-i; j<100; j++) cout <<"2";    
        cout << "0";
        for(int j=i; j<99; j++) cout <<"2";
        cout << '\n' << flush;
        
        cin >> n;

        if (n>k) {
            arr[i] = 2;
        } else if (n==k) {
            arr[i] = 0;
        } else {
            arr[i] = 5;
        }
        i++;
    }
    cout << "! ";
    for(int j=0; j<100; j++) cout << arr[j] << flush;
}