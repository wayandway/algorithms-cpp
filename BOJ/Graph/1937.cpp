#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MN = 501;

int dp[MN][MN]; 
int arr[MN][MN]; 
bool visit[MN][MN]; 
int N;
int di[4] = {1, 0, 0, -1}; 
int dj[4] = {0, 1, -1, 0};

int dfs(int i, int j) {
    if(visit[i][j]) return dp[i][j]; 
    visit[i][j] = true; 
    dp[i][j] = 1; 
    for(int d = 0; d < 4; d++) { 
        int ni = i + di[d];
        int nj = j + dj[d];
        if(ni >= 0 && ni < N && nj >= 0 && nj < N) { 
            if(arr[ni][nj] > arr[i][j]) 
                dp[i][j] = max(dp[i][j],dfs(ni, nj) + 1); 
        }
    }
    return dp[i][j]; 
}

int main() {
    cin >> N;
    int ans = 1;
    for(int i = 0; i < N; i++) { 
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans = max(ans,dfs(i, j)); 
        }
    }

    cout << ans; 
    return 0;
}