#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, ans;
char arr[52][52];
int v[52][52];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs(int x, int y){
    if(arr[x][y] == 'W') return 0;
    
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    v[x][y] = 1;
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = xx+dx[i];
            int ny= yy+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny] == 'L'){
                if(!v[nx][ny]) {
                    q.push(make_pair(nx,ny));
                    v[nx][ny] = v[xx][yy] + 1;
                    cnt = max(cnt, v[nx][ny]);
                }
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            arr[i][j] = s[j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(bfs(i, j), ans);
            for(int k=0;k<n;k++){
                memset(v[k], 0, sizeof(v[k]));
            }
            
        }
    }
    cout << ans-1;
    
    return 0;
}