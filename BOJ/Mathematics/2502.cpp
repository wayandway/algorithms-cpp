#include <iostream>
#include <vector>

using namespace std;

long long dp[33][2];
int main()
{

    int d, k;

    cin>>d>>k;
    dp[1][0] = 1;   
    dp[1][1] = 0;
    dp[2][0] = 0;
    dp[2][1] = 1;

    for (int i = 3; i <=d ;i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }


    for (int i = 1; i * dp[d][0] < k; i++ )
    {
        if (  (k - (i*dp[d][0]))%dp[d][1] == 0 )
        {
            cout<< i << "\n";
            cout<<(k - (i*dp[d][0]))/dp[d][1] <<"\n";
            return 0;
        }
    }
    return 0;
}