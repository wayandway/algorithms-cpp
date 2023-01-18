#include<iostream>
#include<cstring>
 
#define endl "\n"
#define MAX 55
#define INF 2e9
using namespace std;
 
int n, m, answer;
int map[MAX][MAX];
int sum[MAX][MAX];
int memo[MAX][MAX][MAX][MAX];
 
int min(int A, int B) { if (A < B) return A; return B; }
 
void init()
{
    memset(sum, 0, sizeof(sum));
    memset(memo, -1, sizeof(memo));
}
 
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
}
 
void calc_sum()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
        }
    }
}
 
int DFS(int x, int y, int Ex, int Ey)
{
    if (x == Ex && y == Ey) return 0;
    if (memo[x][y][Ex][Ey] != -1) return memo[x][y][Ex][Ey];
 
    memo[x][y][Ex][Ey] = INF;
    int current_sum = sum[Ex][Ey] - sum[x - 1][Ey] - sum[Ex][y - 1] + sum[x - 1][y - 1];
    for (int i = x; i < Ex; i++)
    {
        int result1 = DFS(x, y, i, Ey);
        int result2 = DFS(i + 1, y, Ex, Ey);
        memo[x][y][Ex][Ey] = min(memo[x][y][Ex][Ey], result1 + result2 + current_sum);
    }
    for (int i = y; i < Ey; i++)
    {
        int result1 = DFS(x, y, Ex, i);
        int result2 = DFS(x, i + 1, Ex, Ey);
        memo[x][y][Ex][Ey] = min(memo[x][y][Ex][Ey], result1 + result2 + current_sum);
    }
 
    return memo[x][y][Ex][Ey];
    
}
 
void solution()
{
    calc_sum();
    answer = DFS(1, 1, n, m);
}
 
void solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        init();
        input();
        solution();
 
        cout << "#" << T << " " << answer << endl;
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("input.txt", "r", stdin);
    solve();
 
    return 0;
}