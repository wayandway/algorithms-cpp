#include<iostream>
#include<vector>
#include<cstring>
 
#define endl "\n"
#define MAX 20
using namespace std;
 
int H, W, N;
char MAP[MAX][MAX];
 
vector<char> Cmd;
pair<pair<int, int>, int> Tank;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Initialize()
{
    Tank.first.first = Tank.first.second = Tank.second = -1;
    Cmd.clear();
    memset(MAP, 0, sizeof(MAP));
}
 
void Input()
{
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == '<' || MAP[i][j] == '>' || MAP[i][j] == '^' || MAP[i][j] == 'v')
            {
                Tank.first.first = i;
                Tank.first.second = j;
                if (MAP[i][j] == '<') Tank.second = 1;
                else if (MAP[i][j] == '>') Tank.second = 0;
                else if (MAP[i][j] == '^') Tank.second = 3;
                else if (MAP[i][j] == 'v') Tank.second = 2;
            }
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char A; cin >> A;
        Cmd.push_back(A);
    }
}
 
void Shooting()
{
    int x = Tank.first.first;
    int y = Tank.first.second;
    int dir = Tank.second;
 
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    while (1)
    {
        if (nx < 0 || ny < 0 || nx >= H || ny >= W) break;
 
        if (MAP[nx][ny] == '#') break;
        else if (MAP[nx][ny] == '*')
        {
            MAP[nx][ny] = '.';
            break;
        }
        else
        {
            nx = nx + dx[dir];
            ny = ny + dy[dir];
        }
    }
}
 
void Solution()
{
    for (int i = 0; i < Cmd.size(); i++)
    {
        char C = Cmd[i];
 
        if (C == 'S') Shooting();
        else if (C == 'U')
        {
            Tank.second = 3;
            int x = Tank.first.first;
            int y = Tank.first.second;
            int nx = x + dx[Tank.second];
            int ny = y + dy[Tank.second];
 
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
            {
                MAP[x][y] = '^';
            }
            else
            {
                if (MAP[nx][ny] == '.')
                {
                    Tank.first.first = nx;
                    Tank.first.second = ny;
                    MAP[nx][ny] = '^';
                    MAP[x][y] = '.';
                }
                else MAP[x][y] = '^';
            }
        }
        else if (C == 'D')
        {
            Tank.second = 2;
            int x = Tank.first.first;
            int y = Tank.first.second;
            int nx = x + dx[Tank.second];
            int ny = y + dy[Tank.second];
 
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
            {
                MAP[x][y] = 'v';
            }
            else
            {
                if (MAP[nx][ny] == '.')
                {
                    Tank.first.first = nx;
                    Tank.first.second = ny;
                    MAP[nx][ny] = 'v';
                    MAP[x][y] = '.';
                }
                else MAP[x][y] = 'v';
            }
        }
        else if (C == 'L')
        {
            Tank.second = 1;
            int x = Tank.first.first;
            int y = Tank.first.second;
            int nx = x + dx[Tank.second];
            int ny = y + dy[Tank.second];
 
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
            {
                MAP[x][y] = '<';
            }
            else
            {
                if (MAP[nx][ny] == '.')
                {
                    Tank.first.first = nx;
                    Tank.first.second = ny;
                    MAP[nx][ny] = '<';
                    MAP[x][y] = '.';
                }
                else MAP[x][y] = '<';
            }
        }
        else if (C == 'R')
        {
            Tank.second = 0;
            int x = Tank.first.first;
            int y = Tank.first.second;
            int nx = x + dx[Tank.second];
            int ny = y + dy[Tank.second];
 
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
            {
                MAP[x][y] = '>';
            }
            else
            {
                if (MAP[nx][ny] == '.')
                {
                    Tank.first.first = nx;
                    Tank.first.second = ny;
                    MAP[nx][ny] = '>';
                    MAP[x][y] = '.';
                }
                else MAP[x][y] = '>';
            }
        }
    }
}
 
void Print()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << MAP[i][j];
        }
        cout << endl;
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
 
        cout << "#" << T << " ";
        Print();
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