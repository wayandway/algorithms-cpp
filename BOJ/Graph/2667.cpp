#include <bits/stdc++.h>
using namespace std;

int N;
int board[25][25];
bool visited[25][25];

int cnt = 0; 
int dx[4] = {-1,0,1,0}; 
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q; 
vector<int> res; 
void bfs(void)
{
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        cnt++;
        q.pop();
        for(int d = 0; d<4; d++)
        {
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx<0 || nx >= N || ny <0 || ny >= N) continue; 
            if(visited[nx][ny] == true) continue; 
            if(board[nx][ny]==1)
            {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
            
        }
    }
    res.push_back(cnt); 
}

void solve(void){
    for(int i = 0 ; i<N; i++)
    {
        for(int j = 0 ; j<N; j++)
        {
            if(board[i][j] ==1 && visited[i][j] == false) 
            {
                cnt++;
                q.push({i,j});
                visited[i][j]=true;
                bfs();
            }
        }
    }
}
int main(void)
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0 ; j< N; j++)
        {
            board[i][j] = temp[j]-'0';
        }
    }
    solve();
    sort(res.begin(), res.end()); 
    cout << cnt << '\n';
    for(int i =0 ; i< res.size(); i++)
    {
        cout << res[i] << '\n';
    }
}