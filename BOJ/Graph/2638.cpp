#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int map[101][101];
bool chk[101][101];

int N, M;
int time_count = 0;
int c_area = 0;

queue<pair<int, int>> cheese;

struct Data {
	int y, x;
};

bool range(int b, int a) {
	if (b >= 0 && b < M && a >= 0 && a < N)
		return 1;
	return 0;
}

void bfs(int y, int x) {
	queue<Data> q;
	q.push({ y,x });
	chk[y][x] = 1;

	while (!q.empty()) {
		Data now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Data next;
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];
			if (range(next.y, next.x) && !chk[next.y][next.x] && map[next.y][next.x] == 0) {
				map[next.y][next.x] = 2;
				chk[next.y][next.x] = true;
				q.push(next);
			}
		}
	}
}

void air_solve(int y,int x) {
	int air_count = 0;
	if (map[y][x + 1] == 2)
		air_count++;
	if (map[y + 1][x] == 2)
		air_count++;
	if (map[y][x - 1] == 2)
		air_count++;
	if (map[y - 1][x] == 2)
		air_count++;

	if (air_count >= 2) {
		cheese.push(make_pair(y, x));
	}
}

void cheese_area() {
	c_area = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1)
				c_area++;
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	map[0][0] = 2;
	bfs(0, 0);
	memset(chk, false, sizeof(chk));

	while (1) {
		time_count++;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if(map[i][j]==1)
					air_solve(i,j);
			}
		}

		int c_idx = cheese.size();
		for (int i = 0; i < c_idx; i++) {
			map[cheese.front().first][cheese.front().second] = 2;
			cheese.pop();
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 2)
					bfs(i, j);
			}
		}
		memset(chk, false, sizeof(chk));
		cheese_area();
		if (c_area == 0)
			break;
	}
	cout << time_count << endl;
}