#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[101][101];
 
int dfs(int m , int n , vector<vector<int>> picture ,int a, int b) {
    visit[a][b] = true;
    int cnt = 1;    
 
    for (int i = 0; i < 4; i++) {
        int x = a + dx[i];
        int y = b + dy[i];
 
        if (x >= m || y >= n || x < 0 || y < 0) continue;
        if (picture[x][y] == picture[a][b] && !visit[x][y]) {
            cnt+=dfs(m, n, picture, x, y);
        }
    }
    return cnt;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
 
    memset(visit, 0, sizeof(visit));
 
    for(int i=0 ; i<m ; i++)
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !visit[i][j]) {                
                max_size_of_one_area = max(max_size_of_one_area,dfs(m, n, picture, i, j));
                number_of_area++;
            }
        }
 
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
