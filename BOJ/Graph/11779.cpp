#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

#define INF 1000000000

int n, m, s, e, a, b, c;
int Dijkstra[1001];
int route[1001];
vector<pair<int,int>> map[1001];
queue<int> q;
stack<int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++)
		Dijkstra[i] = INF;

	cin >> s >> e;

	Dijkstra[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int now_node = q.front();
		int now_cost = Dijkstra[now_node];
		q.pop();

		for (int i = 0; i < map[now_node].size(); i++) {
			int next_node = map[now_node][i].first;
			int next_cost = map[now_node][i].second;

			if (Dijkstra[next_node] > now_cost + next_cost) {
				Dijkstra[next_node] = now_cost + next_cost;
				q.push(next_node);
				route[next_node] = now_node;
			}
		}
	}

	cout << Dijkstra[e] << '\n';

	int u = e;

	while (true) {
		ans.push(u);
		if (u == s) break;
		u = route[u];
	}

	cout << ans.size() << '\n';

	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

}