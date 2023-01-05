#include <iostream>
#include <queue>
 
#define MAX 100000
#define endl "\n"
using namespace std;
 
int N;
int Arr[MAX];
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
}
 
void Solution()
{
    priority_queue<int> PQ;
    for (int i = 0; i < N; i++) PQ.push(-Arr[i]);
    
    int Answer = 0;
    int Compare_Cnt = 0;
 
    while (PQ.empty() == 0)
    {
        if (Compare_Cnt == N - 1) break;
        int Num1 = -PQ.top(); PQ.pop();
        int Num2 = -PQ.top(); PQ.pop();
        
        Answer = Answer + (Num1 + Num2);
        PQ.push(-(Num1 + Num2));
        Compare_Cnt++;
    }
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