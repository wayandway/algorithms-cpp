#include <iostream>
#include <queue>
using namespace std;

int test;
char map[102][102];
bool visit[102][102];
bool key[28];
int m, n;
int sum = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool iskey(int x, int y)
{
    return map[y][x] >= 'a' && map[y][x] <= 'z';
}

bool isposs(int x, int y)
{
    if (x < 0 || y < 0 || x > m + 1 || y > n + 1 || map[y][x] == '*' || visit[y][x])
        return false;
    else if (map[y][x] == '.' || map[y][x] == '$' || iskey(x, y) || map[y][x] == 0)
        return true;
    else if ((map[y][x] >= 'A' && map[y][x] <= 'Z') && key[map[y][x] - 'A'])
        return true; // it is door & has a key
    else
        return false;
}

void bfs()
{
    queue<pair<int, int>> q;

    int k = 1;
    sum = 0;

    while (k > 0)
    {
        k = 0;
        q.push({0, 0});

        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
            {
                visit[i][j] = false;
            }
        }

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int lx = cur.first + dx[dir];
                int ly = cur.second + dy[dir];

                if (isposs(lx, ly))
                {

                    if (iskey(lx, ly))
                    {
                        key[map[ly][lx] - 'a'] = true;
                        map[ly][lx] = '.';
                        k++;
                    }

                    else if (map[ly][lx] == '$')
                    {
                        sum++;
                        map[ly][lx] = '.';
                    }
                    q.push({lx, ly});
                    visit[ly][lx] = true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> test;
    for (int t = 0; t < test; t++)
    {

        cin >> n >> m;

        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
            {
                if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                    map[i][j] = '.';
                else
                    cin >> map[i][j];
            }
        }

        string str;
        cin >> str;

        for (int i = 0; i < 28; i++)
            key[i] = false;

        if (str[0] != '0')
        {
            for (auto c : str)
            {
                key[c - 'a'] = true;
            }
        }

        bfs();

        cout << sum << '\n';
    }
    return 0;
}