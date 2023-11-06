#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct Point {
    ld x, y;
    Point(ld x=0, ld y=0): x(x), y(y) {}
    bool operator < (const Point &p) {
        return y==p.y ? x<p.x : y<p.y; 
    }
};
Point operator - (const Point &a, const Point &b) {
    return Point(a.x-b.x, a.y-b.y);
}
Point operator + (const Point &a, const Point &b) {
    return Point(a.x+b.x, a.y+b.y);
}
Point p[101010];

ll ccw(const Point &a, const Point &b, const Point &c) {
    return a.x*b.y+b.x*c.y+c.x*a.y-(b.x*a.y+c.x*b.y+a.x*c.y);
}

ld dist(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool comp(const Point &a, const Point &b) {
    ll c = ccw(p[0], a, b);
    if(c==0) return dist(p[0], a) < dist(p[0], b);
    return c > 0;
}

int n;
int s[101010];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed;
    cout.precision(7);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        ld x, y; cin >> x >> y;
        p[i] = Point(x,y);
    }
    if (n==2) {
        cout << dist(p[0], p[1]);
        return 0;
    }

    sort(p, p+n);
    stable_sort(p+1, p+n, comp);
    s[0] = 0; s[1] = 1;
    int top = 2;
    for(int i=2; i<n; i++) {
        while(top>=2 && ccw(p[i], p[s[top-2]], p[s[top-1]])<=0) top--;
        s[top++] = i;
    }
    int r=0;
    ld ans=0;
    n = top;
    
    for (int i=0; i<n; i++) {
        while(r<n*2 && ccw(p[s[i]], p[s[(i+1)%n]], p[s[(i+1)%n]]+p[s[(r+1)%n]]-p[s[r%n]])>=0) {
            ans = max(ans, dist(p[s[i]], p[s[r%n]]));
            r++;
        }
        ans = max(ans, dist(p[s[i]], p[s[r%n]]));
    }
    cout << ans;
    return 0;
}