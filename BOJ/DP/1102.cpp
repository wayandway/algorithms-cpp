#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define INF 987654321
using namespace std;

int cost[17][17];
int dp[100000]; 
int P;
int N;

int sol(int visited, int cnt) {
	
	if (P == cnt) {
		return 0;
	}

	int& ret = dp[visited];
	if (ret != -1) return ret;
	ret = INF;

	for (int j = 0; j < N; j++) {
		if (!((1 << j) & visited)) {
			for (int i = 0; i < N; i++) {
				if (i == j) continue;

				if (((1 << i) & visited)) { 
					ret = min(ret, sol(visited | (1 << j), cnt + 1) + cost[i][j]);
				}

			}
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];

	int visited = 0;
	string str; cin >> str;
	cin >> P;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'Y') {
			P--;
			visited |= (1 << i);
		}
	}
	
	if (P <= 0) {
		cout << 0;
		return 0;
	}

	int ans = sol(visited, 0);
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}