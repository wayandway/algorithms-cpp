#include <iostream>
#include <vector>
#include <queue>
#define max 1001
#define infy 98765432
using namespace std;
int N,M;
int dist[max];
vector <pair<int,int>> adj[max];
int trace[max];

void set(void){
    for(int i = 0;i<=N;i++){dist[i] = infy;}
}

void dijkstra(int node){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,node));
    while(!pq.empty()){
        node = pq.top().second;
        pq.pop();
        int cost = pq.top().first;
        if(cost>dist[node]){continue;}
        for(int i = 0;i<adj[node].size();i++){
            int next_node = adj[node][i].first;
            int new_val = adj[node][i].second+dist[node];
            int before_val = dist[next_node];
            if(new_val<before_val){
                dist[next_node] = new_val;
                pq.push({-1*new_val,next_node});
                trace[next_node] = node;
            }
        }
    }
}

void solve(void){
    cout << N-1 << "\n";
    for(int i = 2;i<=N;i++){
        cout << trace[i] << " " << i <<"\n"; 
    }
}

int main(void){
    cin >> N >> M;
    for(int i = 0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    set();
    dist[1] = 0;
    dijkstra(1);
    solve();
}