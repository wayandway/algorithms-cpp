#include <iostream>
#include <cstring>
 
#define endl "\n"
#define MAX 100010
using namespace std;
 
int N, H, Answer;
int Train_Len[MAX];
int Light[MAX];
 
void Initialize()
{
    Answer = 0;
    memset(Light, 0, sizeof(Light));
}
 
void Input()
{
    cin >> N >> H;
    for (int i = 0; i < N; i++) cin >> Train_Len[i];
    for (int i = 0; i < N; i++) cin >> Light[i];
}
 
void Solution()
{
    if (Light[0] == 0) 
    { 
        Light[0] = 1; 
        Answer++; 
    }
    if (Light[N - 1] == 0)
    {
        Light[N - 1] = 1;
        Answer++;
    }
    
    int Off_Time = 0;
    for (int i = 0; i < N; i++)
    {
        if (Light[i] == 1) Off_Time = 0;
        else Off_Time = Off_Time + Train_Len[i];
 
        if (Off_Time >= H)
        {
            Light[i] = 1;
            Answer++;
            Off_Time = 0;
        }
    }
}
 
void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();
 
        cout << "#" << T << " " << Answer << endl;
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}
