// https://www.acmicpc.net/problem/1026
#include <iostream>
#include <algorithm>
 
#define endl "\n"
#define MAX 50
using namespace std;
 
int N;
int Arr_A[MAX];
int Arr_B[MAX];
bool Select[MAX];
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> Arr_A[i];
    for (int i = 0; i < N; i++) cin >> Arr_B[i];
}
 
bool Cmp(int A, int B)
{
    if (A > B) return true;
    return false;
}
 
void Solution()
{
    sort(Arr_A, Arr_A + N);
    sort(Arr_B, Arr_B + N, Cmp);
    int Sum = 0;
    for (int i = 0; i < N; i++) Sum = Sum + (Arr_A[i] * Arr_B[i]);
    
    cout << Sum << endl;
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
