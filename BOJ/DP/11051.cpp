#include <iostream>
 
#define endl "\n"
#define MAX 1010
#define MODULER 10007
using namespace std;
 
int N, K;
int DP[MAX][MAX];
 
void Input()
{
    cin >> N >> K;
}
 
void Solution()
{
    if (N == 0)
    {
        cout << 0 << endl;
        return;
    }
 
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            if (j == 0) DP[i][j] = 1;
            else if (i == j) DP[i][j] = 1;
            else DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
 
            DP[i][j] = DP[i][j] % MODULER;
        }
    }
    cout << DP[N][K] % MODULER << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}
