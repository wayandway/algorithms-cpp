#include <iostream>
 
#define endl "\n"
#define MAX 1010
#define MODULER 10007
using namespace std;
 
int N;
int DP[MAX];
 
void Input()
{
    cin >> N;
}
 
void Solution()
{
    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
        DP[i] = DP[i] % MODULER;
    }
    cout << DP[N] << endl;
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
