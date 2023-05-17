#include<iostream>
#include<set>
 
typedef long long ll;
#define endl "\n"
#define INF 987654321
using namespace std;
 
int Fried_Cost, Spicy_Cost, Half_Cost, Fried_Num, Spicy_Num;
int Answer;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
    cin >> Fried_Cost >> Spicy_Cost >> Half_Cost >> Fried_Num >> Spicy_Num;
    Half_Cost = Half_Cost * 2;
}
 
 
void Solution()
{
    int Temp_Answer = 0;
    int Temp_Answer2 = 0;
 
    if (Fried_Cost + Spicy_Cost > Half_Cost)
    {
        int Min_Chicken;
 
        if (Fried_Num < Spicy_Num)
        {
            Min_Chicken = Fried_Num;
 
            int Temp = 0;
            while (Min_Chicken--)
            {
                Temp = Temp + Half_Cost;
                Spicy_Num--;
            }
 
            Temp_Answer = Temp;
            Temp_Answer2 = Temp;
 
            int Cnt = Spicy_Num;
            while (Spicy_Num--)    Temp_Answer = Temp_Answer + Spicy_Cost;
            while (Cnt--)    Temp_Answer2 = Temp_Answer2 + Half_Cost;
 
            Answer = Min(Temp_Answer, Temp_Answer2);
        }
        else
        {
            Min_Chicken = Spicy_Num;
 
            int Temp = 0;
            while (Min_Chicken--)
            {
                Temp = Temp + Half_Cost;
                Fried_Num--;
            }
 
            Temp_Answer = Temp;
            Temp_Answer2 = Temp;
 
            int Cnt = Fried_Num;
            while (Fried_Num--) Temp_Answer = Temp_Answer + Fried_Cost;
            while (Cnt--) Temp_Answer2 = Temp_Answer2 + Half_Cost;
 
            Answer = Min(Temp_Answer, Temp_Answer2);
        }
    }
    else
    {
        Answer = Fried_Cost * Fried_Num + Spicy_Num * Spicy_Cost;
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
