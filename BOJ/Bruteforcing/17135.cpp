#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
 
#define endl "\n"
#define MAX 15
using namespace std;
 
typedef struct
{
    int x;
    int y;
    int Dist;
}Enemy_Info;
 
int N, M, D, Answer, Temp_Answer;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
bool Visit[MAX][MAX];
bool Select[MAX];
vector<pair<int, int>> V;
vector<int> Pos;
 
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void Copy_MAP()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C_MAP[i][j] = MAP[i][j];
        }
    }
}
 
bool All_Kill()
{
    bool Flag = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (C_MAP[i][j] == 1)
            {
                Flag = false;
                V.push_back(make_pair(i, j));
            }
        }
    }
    return Flag;
}
 
int Dist(int x, int y, int xx, int yy)
{
    return abs(x - xx) + abs(y - yy);
}
 
bool Standard(Enemy_Info A, Enemy_Info B)
{
    if (A.Dist <= B.Dist)
    {
        if (A.Dist == B.Dist)
        {
            if (A.y < B.y)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
 
void Shot()
{
    pair<int, int> Arrow_Target[3];
 
    for (int i = 0; i < Pos.size(); i++)
    {
        int x = N;
        int y = Pos[i];
        vector<Enemy_Info> Kill_Enemy_Temp;
 
        for (int j = 0; j < V.size(); j++)
        {
            int xx = V[j].first;
            int yy = V[j].second;
 
            int Distance = Dist(x, y, xx, yy);
            if (Distance <= D)
            {
                Enemy_Info Temp;
                Temp.x = xx;
                Temp.y = yy;
                Temp.Dist = Distance;
                Kill_Enemy_Temp.push_back(Temp);
            }
        }
 
        int Kill_Num = Kill_Enemy_Temp.size();
        if (Kill_Num > 1)
        {
            sort(Kill_Enemy_Temp.begin(), Kill_Enemy_Temp.end(), Standard);
            Arrow_Target[i].first = Kill_Enemy_Temp[0].x;
            Arrow_Target[i].second = Kill_Enemy_Temp[0].y;
        }
        else if (Kill_Num == 1)
        {
            Arrow_Target[i].first = Kill_Enemy_Temp[0].x;
            Arrow_Target[i].second = Kill_Enemy_Temp[0].y;
        }
        else
        {
            Arrow_Target[i].first = -1;
            Arrow_Target[i].second = -1;
        }
    }
 
    for (int i = 0; i < 3; i++)
    {
        int x = Arrow_Target[i].first;
        int y = Arrow_Target[i].second;
        
        if (x == -1 && y == -1) continue;
        if (Visit[x][y] == false)
        {
            Visit[x][y] = true;
            C_MAP[x][y] = 0;
            Temp_Answer++;
        }
    }
}
 
void Move_Enemy()
{
    for (int i = V.size() - 1; i >= 0; i--)
    {
        int x = V[i].first;
        int y = V[i].second;
 
        if (C_MAP[x][y] == 0) continue;
        if (x == N - 1)
        {
            C_MAP[x][y] = 0;
        }
        else
        {
            C_MAP[x][y] = 0;
            C_MAP[x + 1][y] = 1;
        }
    }
}
 
void Print()
{
    cout << "#######################################################" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << C_MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << "#######################################################" << endl;
}
 
void Kill_The_Enemy()
{
    Copy_MAP();
    while (1)
    {
        V.clear();
        memset(Visit, false, sizeof(Visit));
 
        if (All_Kill() == true) break;
        Shot();
        Move_Enemy();
    }
}
 
void Select_Pos(int Idx, int Cnt)
{
    if (Cnt == 3)
    {
        Temp_Answer = 0;
        Kill_The_Enemy();
        Answer = Bigger(Answer, Temp_Answer);
        return;
    }
 
    for (int i = Idx; i < M; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        Pos.push_back(i);
        Select_Pos(i, Cnt + 1);
        Pos.pop_back();
        Select[i] = false;
    }
}
 
void Solution()
{
    Select_Pos(0, 0);
}
 
void Solve()
{
    Input();
    Solution();
    cout << Answer << endl;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}