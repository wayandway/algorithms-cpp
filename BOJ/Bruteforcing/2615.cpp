#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int N=19;
int map[20][20];
bool visit[20][20][4];
int dy[] = { 0, 1, 1, 1 };
int dx[] = { 1, 1, 0, -1 };
vector<pair<int, int>> pos;
 
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second >= b.second)
        if (a.second == b.second)
            if (a.first > b.first)
                return false;
            else
                return true;
        else
            return false;
    else
        return true;
}
 
bool isrange(int y, int x) {
    if (y<1 || x<1 || y>N || x>N) return false;
    return true;
}
 
int check_next(int now_y, int now_x, int dir, int val, int cnt) {
    visit[now_y][now_x][dir] = true;
    pos.push_back(make_pair(now_y, now_x));
    
    int next_y = now_y + dy[dir];
    int next_x = now_x + dx[dir];
    if (!isrange(next_y, next_x) || map[next_y][next_x] != val) return cnt;
 
    return check_next(next_y, next_x, dir, val, cnt + 1);
}
 
int main() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 0)continue;
            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];
 
                if (!isrange(ny, nx))continue;
                if (map[ny][nx] == map[i][j] && !visit[i][j][d]) {
                    pos.clear();
                    visit[i][j][d] = true;
                    pos.push_back(make_pair(i, j));
                    if (check_next(ny, nx, d, map[i][j], 2) == 5) {
                        sort(pos.begin(), pos.end(), cmp);
                        cout << map[i][j] << endl;
                        cout << pos[0].first << ' ' << pos[0].second;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0;
    return 0;
}