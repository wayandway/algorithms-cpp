#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_N 101
#define MAX_V 1001
using namespace std;

int loc[MAX_N];
int dist[MAX_V][MAX_V];
long long int shortest[2][MAX_V];
int n, v, e, goal1, goal2, temp1, temp2, tempv, nextv;
long long int tempd, ans = 0;
int cnt = 0;

priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> q;

void dijkstra(int loc, vector < vector<int>> adj) {
	shortest[cnt][loc] = 0;
	tempv = loc;
	tempd = 0;
	long long int nextd;
	int nextv;
	q.push(make_pair(0, loc));
	while (!q.empty()) {
		tempd = q.top().first;
		tempv = q.top().second;
		q.pop();
		for (auto e : adj[tempv]) {
			nextv = e;
			nextd = tempd + dist[tempv][nextv];
			if (shortest[cnt][nextv] != -1&& nextd >= shortest[cnt][nextv])continue;
			else {
				shortest[cnt][nextv] = nextd;
				q.push(make_pair(nextd, nextv));
			}
		}
	}
	return;
}

int main() {
	memset(shortest, -1, sizeof(shortest));
	cin >> n >> v >> e >> goal1 >> goal2;
	vector<vector<int>> adj(v + 1, vector<int>(0,0));
	for (int i = 0;i < n;i++) {
		cin >> loc[i];
	}
	for (int i = 0;i < v;i++)dist[i][i] = 0;
	for (int i = 0;i < e;i++) {
		cin >> temp1 >> temp2 >> tempd;
		if (dist[temp1][temp2] != 0 && tempd > dist[temp1][temp2])continue;
		dist[temp1][temp2] = dist[temp2][temp1] = tempd;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}
	dijkstra(goal1, adj);cnt++;
	dijkstra(goal2, adj);
	for (int i = 0;i < n;i++) {
		if (shortest[0][loc[i]] == -1)ans += -1;
		else ans += shortest[0][loc[i]];
		if (shortest[1][loc[i]] == -1)ans += -1;
		else ans += shortest[1][loc[i]];
	}
	cout << ans;
	return 0;
}