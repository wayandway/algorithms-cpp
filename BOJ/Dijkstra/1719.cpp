#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
const int inf = 2e9;
const int SIZE = 1 << 18;
const int MOD = 1e9 + 7;

vector<pii> adj[1001];
int dist[1001];
int prevv[1001];

void dijkstra(int start) {
	for (int i = 0; i < 1001; i++) dist[i] = inf;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int cur_dist = pq.top().X;
		int cur_node = pq.top().Y;
		pq.pop();
		if (dist[cur_node] < cur_dist) continue;
		for (pii next : adj[cur_node]) {
			int next_node = next.X;
			int next_dist = dist[cur_node] + next.Y;
			if (next_dist >= dist[next_node]) continue;
			dist[next_node] = next_dist;
			prevv[next_node] = cur_node;
			pq.push({next_dist, next_node});
		}
	}
}

int findAns(int start, int end) {
	while (1) {
		if (prevv[end] == start) return end;
		end = prevv[end];
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<int> num;
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		num.push_back(u);
		num.push_back(v);
		adj[u].push_back({v, cost});
		adj[v].push_back({u, cost});
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	for (int i = 0; i < n; i++) {
		string s = "";
		dijkstra(num[i]);
		for (int j = 0; j < n; j++) {
			if (i == j) {
				s += "- ";
				continue;
			}
			s += to_string(findAns(num[i], num[j])) + " ";
		}
		cout << s << '\n';
	}
	return 0;
}