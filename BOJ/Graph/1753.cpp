#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 1e9 + 10
#define pi pair<int, int>

int v, e, st;
using namespace std;
vector<pi> adj[20005];
int d[20005] = { 0, };

void dijkstra() {
    fill(d, d + 20005, INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    d[st] = 0;
    pq.push({ d[st],st });
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int dist = cur.first, idx = cur.second;
        if (d[idx] != dist) continue;
        for (auto& nxt : adj[idx]) {
            int cost = nxt.first;
            int nidx = nxt.second;
            if (d[nidx] > dist + cost) {
                d[nidx] = dist + cost;
                pq.push({ d[nidx],nidx });
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) cout << "INF" << "\n";
        else cout << d[i] << "\n";
    }
}
int main(void) {
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(NULL);
    int a, b, c;
    cin >> v >> e >> st;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
    }
    dijkstra();
}