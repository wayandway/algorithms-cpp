#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int N, M;
int mars[1001][1001];
int visited[1000][1000];
int cache[1001][1001][3];
const int dy[3] = { 1,0,0 };
const int dx[3] = { 0,1,-1 };
const int MINF = -1000000;
int solve(int y, int x, int dir)
{


	if (y == N - 1 && x == M-1) {
		return mars[y][x];
	}

	int& ret = cache[y][x][dir];

	if (ret != MINF) return ret;


	for (int i = 0; i < 3; ++i)
	{

		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		ret = max(ret, solve(ny, nx, i) + mars[y][x]);
		visited[ny][nx] = false;
	}

	return ret;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> mars[i][j];
			cache[i][j][0] = cache[i][j][1] = cache[i][j][2] = MINF;
		}

	visited[0][0] = true;
	cout << solve(0, 0,0) << "\n";
	

	return 0;
}