#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

struct Point {
    ll x, y;
    Point(ll x, ll y): x(x), y(y) {}
    bool operator < (const Point &p) {
        return y==p.y ? x<p.x : y<p.y;
    }
};
Point p[10001];


ll ccw(const Point &a, const Point &b, const Point &c) {
    // (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y)
    return a.x*b.y+b.x*c.y+c.x*a.y-(b.x*a.y+c.x*b.y+a.x*c.y);
}

ll dist(Point a, Point b) {
    return sqrt(a.x-b.x)+sqrt(a.y-b.y);
}

bool comp(const Point &a, const Point &b) {
    ll c = ccw(p[0], a, b);
    if(c==0) return dist(p[0], a) < dist(p[0], b);
    return c>0;
}
int n;
stack<int> st;

int main() {
    cin >> n;
    sort(p, p+n);
    sort(p+1, p+n, comp);
    st.push(0);
    st.push(1);
    int next = 2;
    while (next<n) {
        while (st.size() >= 2) {
            int first, second;
            second = st.top();
            st.pop();
            first = st.top();
            if(ccw(p[first], p[second], p[next])>0) {
                st.push(second);
                break;
            }
        }
        st.push(next++);
    }
    return 0;
}