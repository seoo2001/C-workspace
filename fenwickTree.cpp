// tree의 길이 = 배열의 길이

// 구간 수정 쿼리, index 값 구하는 쿼리

#include <bits/stdc++.h>
#define tSize 101010
using namespace std;
typedef long long ll;

int tree[tSize];

void update(int idx, ll v) {
    while(idx<=tSize) {
        tree[idx] += v;
        idx += (idx&-idx);
    }
}
// sum(0 ~ idx)
ll sum(int idx) {
    ll s = 0;
    while(idx>0) {
        s += tree[idx];
        idx -= (idx&-idx);
    }
    return s;
}

// 구간으로 업데이트
void f(int s, int e, int val) {
    update(s, val);
    update(e+1, val);
}


int main() {
    f(1, 4, 3);
    cout << sum(2);
}