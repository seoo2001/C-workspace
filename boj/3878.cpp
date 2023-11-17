#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;

struct Point {
    int x, y;
    Point(int x=0, int y=0): x(x), y(y) {}
    bool operator < (const Point &p) {
        return y==p.y ? x<p.x : y<p.y;
    }
};
Point black[105], white[105];

int ccw(const Point &a, const Point &b, const Point &c) {
    return a.x*b.y+b.x*c.y+c.x*a.y-(b.x*a.y+c.x*b.y+a.x*c.y);
}

int dist(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool compb(const Point &a, const Point &b) {
    int c = ccw(black[0], a, b);
    if(c==0) return dist(black[0], a) < dist(black[0], b);
    return c>0;
}
bool compw(const Point &a, const Point &b) {
    int c = ccw(white[0], a, b);
    if(c==0) return dist(white[0], a) < dist(white[0], b);
    return c>0;
}

int makeStack(Point* pl, int* s, int ch) {
    if (ch) {
        sort(pl, pl+n);
        stable_sort(pl+1, pl+n, compb);
    } 
    else {
        sort(pl, pl+m);
        stable_sort(pl+1, pl+m, compw);
    }
    int top = 2;
    s[0] = 0; s[1] = 1;
    for(int i=2; i<n; i++) {
        while(top>=2 && ccw(pl[i], pl[s[top-2]], pl[s[top-1]])<=0) top--;
        s[top++] = i;
    }
    return top;
}

bool check(const Point &a, const Point &b, const Point &c, const Point &d) {
    Point p1 = a;
    Point p2 = b;
    Point p3 = c;
    Point p4 = d;
    ll ab = 1ll*ccw(p1, p2, p3) * ccw(p1, p2, p4);
    ll cd = 1ll*ccw(p3, p4, p1) * ccw(p3, p4, p2);
    if (ab==0 && cd==0) {
        if (p2<p1) swap(p1, p2);
        if (p4<p3) swap(p3, p4);
        return !(p2 < p3) && !(p4 < p1);
    }
    return ab<=0 && cd<=0;
}

int blackS[105];
int whiteS[105];
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            int x, y; cin >> x >> y;
            black[i] = {x, y};
        }
        for(int i=0; i<m; i++) {
            int x, y; cin >> x >> y;
            white[i] = {x, y};
        }
        if (n<=1 && m<=1) {
            cout << "YES\n";
            continue; 
        }
        int bSize = makeStack(black, blackS, 1);
        int wSize = makeStack(white, whiteS, 0);
        
        int ch = false;
        for(int i=0; i<bSize; i++) {
            if (ch) break;
            for(int j=0; j<wSize; j++) {
                if (check(black[blackS[i]], black[blackS[(i+1)%bSize]], white[whiteS[j]], white[whiteS[(j+1)%wSize]])) {
                    cout << "NO\n";
                    ch = true;
                    break;
                }   
            }
        }
        if (ch) continue;
        for(int i=0; i<wSize; i++) {
            if (bSize<3) continue;
            Point p = white[whiteS[i]];
            int s = 2, e = bSize-1, mid;
            while (s<e) {
                mid = (s+e) >> 1;
                if (ccw(black[blackS[0]], black[blackS[mid]],p)<0) e=mid;
                else s=mid+1;
            }
            if (ccw(black[blackS[0]], black[blackS[s-1]], p)>=0 &&ccw(black[blackS[s-1]], black[blackS[s]], p)>=0 &&ccw(black[blackS[s]], black[blackS[0]], p)>=0) {
                cout << "NO\n";
                ch = true;
                break;
            }
        }
        if (ch) continue;
        for(int i=0; i<bSize; i++) {
            if (wSize<3) continue;
            Point p = black[blackS[i]];
            int s = 2, e = wSize-1, mid;
            while (s<e) {
                mid = (s+e) >> 1;
                if (ccw(white[whiteS[0]], white[whiteS[mid]],p)<0) e=mid;
                else s=mid+1;
            }
            if (ccw(white[whiteS[0]], white[whiteS[s-1]], p)>=0 &&ccw(white[whiteS[s-1]], white[whiteS[s]], p)>=0 &&ccw(white[whiteS[s]], white[whiteS[0]], p)>=0) {
                cout << "NO\n";
                ch = true;
                break;
            }
        }
        if (ch) continue;
        cout << "YES\n";
    }    

    return 0;
}