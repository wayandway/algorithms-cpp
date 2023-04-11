#include <iostream>
 
#define endl "\n"
#define MAX 85
using namespace std;
 
int N;
long long Line[MAX][2];
 
void Input()
{
    cin >> N;
}
 
void Solution()
{
    Line[1][0] = 1;
    Line[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            Line[i][1] = Line[i - 1][0] + Line[i - 1][1];
            Line[i][0] = Line[i - 1][0];
        }
        else
        {
            Line[i][0] = Line[i - 1][0] + Line[i - 1][1];
            Line[i][1] = Line[i - 1][1];
        }
    }
    cout << Line[N][0] * 2 + Line[N][1] * 2 << endl;
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
