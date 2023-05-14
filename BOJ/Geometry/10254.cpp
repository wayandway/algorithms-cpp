#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct P{
    ll x, y;
    P operator- (P a) { 
        return { x - a.x, y - a.y };
    }
}b[200001];
vector<P> v;
ll ccw(P p1, P p2) {
    ll ret = p1.x*p2.y - p2.x*p1.y;
    if (ret < 0) return -1;
    else if (ret > 0) return 1;
    else return 0;
}
ll ccw(P c, P a, P b) {
    return ccw(a - c, b - c);
}
ll sqdis(P p1, P p2) {
    return (p1.x - p2.x) *(p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
bool cmp(P p1, P p2) {
    ll ret = ccw(b[0], p1, p2);
    if (ret > 0) return true;
    else if (ret < 0) return false;
    else {
        if (sqdis(b[0], p1) < sqdis(b[0], p2)) return true;
        else return false;
    }
}
int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int Min = 111111111, idx = 0; 
        for (int i = 0; i < n; i++) {
            cin >> b[i].x >> b[i].y;
            if (b[i].y < Min) {
                Min = b[i].y;
                idx = i;
            }
            else if (b[i].y == Min) {
                if (b[i].x < b[idx].x) idx = i;
            }
          }
        swap(b[0], b[idx]);
        sort(b + 1, b + n, cmp);
        
        for (int i = 0; i < n; i++) {
            while (v.size() >= 2 && ccw(v[v.size() - 2], v[v.size() - 1], b[i]) <= 0) {
                v.pop_back(); 
            }
            v.push_back(b[i]);
        }
        v.push_back(b[0]); 
 
        ll ans = -1;
        int j = 1, st, en;
        for (int i = 0; i < v.size()-1; i++) {
            while (i != j && ccw(v[i + 1] - v[i], v[j + 1] - v[j]) > 0) {
                j++;
                if (j >= v.size() - 1) j = 0;
            }
            ll dist = sqdis(v[i], v[j]); 
            if (ans < dist) {
                st = i;
                en = j;
                ans = dist;
            }
        }
        printf("%lld %lld %lld %lld\n", v[st].x, v[st].y, v[en].x, v[en].y);
        v.clear();
    }
    return 0;
}