#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[1000001];
int before[1000001];
int main(void)
{
	cin >> N;

	dp[1] = 0; 
	before[1] = 0;
	for ( int i = 2; i <=N ; i++ )
	{

		dp[i] = dp[i - 1]+1; 
		before[i] = i - 1;

		if (i % 3 == 0 && dp[i]>dp[i/3]+1)
		{
			dp[i] = dp[i / 3] + 1;
			before[i] = i / 3;
		}

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
		{
			dp[i] = dp[i / 2] + 1;
			before[i] = i / 2;
		}

	}

	cout << dp[N]<<"\n";
	while (N != 0) 
	{
		cout << N << " ";
		N = before[N];
	}

}