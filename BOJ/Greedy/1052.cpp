#include<iostream>
 
#define endl "\n"
using namespace std;
 
int N, K, Answer;
 
void Input()
{
    cin >> N >> K;
}
 
int Add_Water(int x)
{
    int Cnt = 0;
    while (x > 0)
    {
        if (x % 2 == 1) Cnt++;
        x = x / 2;
    }
    return Cnt;
}
 
void Solution()
{
    if (N <= K) cout << 0 << endl;
    else
    {
        while (1)
        {
            int Temp_Result = Add_Water(N);
            if (Temp_Result <= K) break;
 
            Answer++;
            N++;
        }
        cout << Answer << endl;
    }
 
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