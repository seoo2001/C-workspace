#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
    Point(ll x=0, ll y=0) : x(x), y(y) {}
    bool operator < (const Point &p) {
        return (y==p.y) ? x < p.x : y < p.y;
    }
};

Point p[101010];

ll ccw(const Point &a, const Point &b, const Point &c) {
    return b.x*c.y+a.x*b.y+c.x*a.y-b.x*a.y-a.x*c.y-c.x*b.y;
}

ll dist(const Point &a, const Point &b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool comp(const Point &a, const Point &b) {
    ll c = ccw(p[0], a, b);
    if(c==0) return dist(p[0], a) < dist(p[0], b);
    return c > 0;
}
stack<int> st;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        p[i] = Point(x, y);
    }
    sort(p, p+n);
    stable_sort(p+1, p+n, comp);
    
    st.push(0); st.push(1);
    int next = 2;
    while(next < n) {
        while (st.size()>=2) {
            int first, second;
            second = st.top();
            st.pop();
            first = st.top();
            if(ccw(p[first], p[second], p[next]) > 0 ) {
                st.push(second);
                break;
            }
        }
        st.push(next++);
    }
    cout << st.size();
}