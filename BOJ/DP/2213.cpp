#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, a, b, x, ans1, ans2;
int V[10001]; 
int dp[10001][2]; 
bool visit[10001];
vector<int> graph[10001];
vector<int> ans;

void DFS(int now)
{
	visit[now] = true;
	dp[now][1] = V[now];

	for (int child : graph[now])
	{
		if (!visit[child])
		{
			DFS(child);

			dp[now][0] += max(dp[child][0], dp[child][1]);

			dp[now][1] += dp[child][0];
		}
	}
}

void tracking(int prev, int now, int state) 
{
	if (state == 1)
	{
		ans.push_back(now);

		for (int child : graph[now])
		{
			if (child == prev) continue;
			
			tracking(now, child, 0);
		}
	}
	else
	{
		for (int child : graph[now])
		{
			if (child == prev) continue;

			if (dp[child][0] > dp[child][1]) 
				tracking(now, child, 0);

			else 
				tracking(now, child, 1);
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> V[i];

	for (int i = 1; i <= n - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1);

	ans1 = dp[1][0];
	ans2 = dp[1][1];

	if (ans1 > ans2) tracking(-1, 1, 0);
	else tracking(-1, 1, 1);

	cout << max(ans1, ans2) << '\n';

	sort(ans.begin(), ans.end());

	for (int x : ans)
	{
		cout << x << " ";
	}
}