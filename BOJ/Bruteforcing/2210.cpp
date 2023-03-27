#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int map[5][5];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
vector<int> v;
 
void DFS(int y, int x, int num, int cnt) {
    if (cnt == 6) {
        v.push_back(num);
        return;
    }
 
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
            continue;
 
        DFS(ny, nx, num * 10 + map[ny][nx], cnt+1);
    }
}
 
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }
 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            DFS(i, j, 0, 0);
        }
    }
 
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
 
    cout << v.size();
}
