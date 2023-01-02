#include <iostream>
#include <queue>
 
#define MAX 100000
#define endl "\n"
using namespace std;
 
int N, Heap_Idx;
int Arr[MAX];
int Heap_Array[MAX + 10];
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
}
 
void Heap_push(int Data)
{
    int Idx = ++Heap_Idx;
    Heap_Array[Idx] = Data;
    while ((Idx != 1) && (Data < Heap_Array[Idx / 2]))
    {
        swap(Heap_Array[Idx], Heap_Array[Idx / 2]);
        Idx = Idx / 2;
    }
}
 
int Heap_pop()
{
    int Result = Heap_Array[1];
    Heap_Array[1] = Heap_Array[Heap_Idx--];
 
    int Parent = 1;
    int Child;
    while (1)
    {
        Child = Parent * 2;
        if (Child + 1 <= Heap_Idx && Heap_Array[Child + 1] < Heap_Array[Child]) Child++;
        if (Child > Heap_Idx || Heap_Array[Parent] < Heap_Array[Child]) break;
        swap(Heap_Array[Child], Heap_Array[Parent]);
        Parent = Child;
    }
    return Result;
}
 
void Solution()
{
    int Answer = 0;
    int Compare_Cnt = N - 1;
    for (int i = 0; i < N; i++) Heap_push(Arr[i]);
    for (int i = 0; i < Compare_Cnt; i++)
    {
        int N1 = Heap_pop();
        int N2 = Heap_pop();
        Answer = Answer + (N1 + N2);
        Heap_push(N1 + N2);
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