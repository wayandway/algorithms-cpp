#include<iostream>
#include<string>
#include<cstring>
 
#define endl "\n"
#define MAX 50
using namespace std;
 
int N, M, Answer;
int MAP[MAX][MAX];
int DP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string S; cin >> S;
        for (int j = 0; j < S.length(); j++)
        {
            if (S[j] == 'H') MAP[i][j] = 0;
            else MAP[i][j] = S[j] - '0';
        }
    }
}
 
int DFS(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M || MAP[x][y] == 0) return 0;
    if (Visit[x][y] == true)
    {
        cout << -1 << endl;
        exit(0);
    }
    if (DP[x][y] != -1) return DP[x][y];
 
    Visit[x][y] = true;
    DP[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + (MAP[x][y] * dx[i]);
        int ny = y + (MAP[x][y] * dy[i]);
        DP[x][y] = Bigger(DP[x][y], DFS(nx, ny) + 1);
    }
    Visit[x][y] = false;
    return DP[x][y];
}
 
void Solution()
{
    memset(DP, -1, sizeof(DP));
    Answer = DFS(0, 0);
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