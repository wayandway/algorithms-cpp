// https://www.acmicpc.net/problem/2206
#include <stdio.h>
#include <queue>
using namespace std;
 
typedef struct {
    int x;
    int y;
    int wall;
}st;
 
int map[1001][1001];
int result[1001][1001];
bool visit[1001][1001][2];
 
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<st> q;
    q.push({ 1,1,0 });
    visit[0][0][0] = visit[0][0][1] = true;
    result[1][1] = 1;
 
    int dx[] = { 1,-1,0,0 };
    int dy[] = { 0,0,1,-1 };
 
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx > 0 && ny > 0 && nx <= N && ny <= M) {
                if (map[nx][ny] == 1 && wall == 0 && !visit[nx][ny][wall + 1]) {
                    visit[nx][ny][wall + 1] = true;
                    result[nx][ny] = result[x][y] + 1;
                    q.push({ nx,ny,wall + 1 });
                }
                if (map[nx][ny] != 1 && !visit[nx][ny][wall]) {
                    visit[nx][ny][wall] = true;
                    result[nx][ny] = result[x][y] + 1;
                    q.push({ nx,ny,wall });
                }
                if (nx == N && ny == M) {
                    printf("%d\n", result[nx][ny]);
                    return 0;
                }
            }
        }
 
    }
 
    if (N == 1 && M == 1) printf("1\n");
    else printf("-1\n");
 
    return 0;
}