#include <iostream>
 
#define endl "\n"
#define MAX 1001
#define Moduler 10007
using namespace std;
 
int N;
int DP[MAX][10];
 
void Input()
{
    cin >> N;
}
 
void Solution()
{
    for (int i = 0; i < 10; i++)
    {
        DP[1][i] = 1;
    }
 
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                DP[i][j] = DP[i][j] + DP[i - 1][k];
                DP[i][j] = DP[i][j] % Moduler;
            }
        }
    }
 
    int Answer = 0;
    for (int i = 0; i < 10; i++)
    {
        Answer = Answer + DP[N][i];
    }
    Answer = Answer % Moduler;
 
    cout << Answer << endl;
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
