#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue> 
#include<cmath> 
using namespace std; 

struct Edge{
    int u, v; double w; 
    Edge(){u = -1; v = -1; w = 0;}
    Edge(int u, int v, double w) : u(u), v(v), w(w) {}
    bool operator <(const Edge & a) const{return w < a.w; }
}; 

struct Circle{
    int x, y, r; 
    Circle(){x = 0; y = 0; r = 0;}
    Circle(int x, int y, int r) : x(x), y(y), r(r){}
    bool operator < (const Circle & a) const{return y < a.y;}
};

vector<Circle> v; 
vector<Edge> e;    
int t, w, n, x, y, r, uf[1004];  

int find(int a){
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    uf[b] = a;
    return true;
}  

double dist(Circle a, Circle b){
    return sqrt(1LL * pow(a.x - b.x, 2.0) + 1LL * pow(a.y - b.y, 2.0));
}

int main(){
    cin >> t; 
    while(t--){
        cin >> w >> n; 
        v.clear(); e.clear(); fill(uf, uf + n + 2, -1);
        for(int i = 0; i < n; i++){
            cin >> x >> y >> r; 
            v.push_back({x, y, r});
        }  
        e.push_back({n, n + 1, (double)w});
        for(int i = 0; i < n; i++){
            e.push_back({i, n, (double)max(0, v[i].x - v[i].r)});
            e.push_back({i, n + 1, (double)max(0, w - v[i].x - v[i].r)}); 
            for(int j = i + 1; j < n; j++){
                double _dist = max(0.0, dist(v[i], v[j]) - v[i].r - v[j].r); 
                e.push_back({i, j, _dist}); 
            }
        }
        sort(e.begin(), e.end());
        for(int i = 0; i < e.size(); i++){ 
            if(merge(e[i].u, e[i].v)){  
                if(find(n) == find(n + 1)){ 
                    if(!e[i].w)puts("0");
                    else printf("%.6lf\n", e[i].w / 2);
                    break; 
                } 
            }
        }
    }  
    return 0;
}