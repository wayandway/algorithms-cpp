#include <iostream>
 
#define endl "\n"
#define MAX 100010
using namespace std;
 
int N;
int DP[MAX];
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
    cin >> N;
}
 
void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        DP[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            DP[i] = Min(DP[i], DP[i - j * j] + 1);
        }
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
