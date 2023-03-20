#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int dp[16] = { 0 };
	int pay[16] = { 0 };
	int time[16] = { 0 };
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> pay[i];
		for (int j = 0; j < i; j++) {
			if (time[j] + j <= i &&i+time[i]<=n+1) {
				dp[i] = max(dp[i], dp[j]+pay[i]);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= n; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer;
	

	return 0;
}