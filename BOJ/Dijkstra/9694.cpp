#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
#define INF 987654321
 
int t, test, n, m;
int d[21];
int path[21];
vector<pair<int, int>> graph[21];
 
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist) continue;
 
        for (auto e : graph[now]) {
            int Next = e.first;
            int nextDist = e.second;
            int cost = dist + nextDist;
            if (cost < d[Next]) {
                d[Next] = cost;
                path[Next] = now;
                pq.push({ -cost, Next });
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n >> m;
 
        for (int i = 0; i < m; i++) {
            graph[i].clear();
        }
 
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({ b,c });
            graph[b].push_back({ a,c });
        }
 
        for (int i = 0; i < m; i++) {
            d[i] = INF;
            path[i] = -1;
        }
        dijkstra(0);
 
        cout << "Case #" << t << ": ";
        if (d[m - 1] == INF) {
            cout << -1;
        }
        else {
            stack<int> s;
            int imsi = m - 1;
            s.push(imsi);
            while (imsi != 0) {
                imsi = path[imsi];
                s.push(imsi);
            }
            while (!s.empty()) {
                cout << s.top() << ' ';
                s.pop();
            }
        }
        cout << '\n';
    }
}
