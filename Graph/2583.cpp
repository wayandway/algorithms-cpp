// https://www.acmicpc.net/problem/2583
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int m, n, k, a, b, c, d;
int ans = 0;
bool visit[101][101];
vector<int> area;
 
void bfs(int a1, int b1){
    queue<pair<int, int>> q;
    q.push(make_pair(a1, b1));
    visit[a1][b1] = true;
    int cnt = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4;i++){
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if (n_x < n && n_x >= 0 && n_y < m && n_y >= 0){
                if(!visit[n_y][n_x]){
                    q.push(make_pair(n_y, n_x));
                    visit[n_y][n_x] = true;
                    cnt++; 
                }
            } 
        }
    }
    area.push_back(cnt);
}
int main(){
    cin >> m >> n >> k;
    for (int i = 0; i < k;i++){
        cin >> a >> b >> c >> d;
        for (int r = b; r < d;r++){ 
            for (int l = a; l < c;l++){ 
                visit[r][l] = true; 
            }
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n;j++){
            if(!visit[i][j]){ 
                bfs(i, j);
                ans++; 
            }
        }
    }
    cout << ans << '\n';
    sort(area.begin(), area.end());
    for (int i = 0; i < area.size(); i++){
        cout << area[i] << " ";
    }
        return 0;
}