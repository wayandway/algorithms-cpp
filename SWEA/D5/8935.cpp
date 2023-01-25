#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
int T, N, M;
int arr[3002], brr[102];
int dp[3002][102][102][2];  

int play(int a, int i, int j, int picked){
    if (dp[a][i][j][picked] != -1) return dp[a][i][j][picked];
    int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
    if (picked) {  
        if(a < N) val1 = play(a + 1, i, j, 0); 
        if(i + j < M) val2 = play(a, i, j + 1, 0);
    } else { 
        if(a < N) {
            val1 = play(a + 1, i, j, 1) + arr[a]; 
            val2 = play(a + 1, i, j, 0); 
        }
        if(i + j < M){
            val3 = play(a, i + 1, j, 1) + brr[i]; 
            val4 = play(a, i + 1, j, 0); 
        }
    }
    return dp[a][i][j][picked] = max(val1, max(val2, max(val3, val4)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++){
        memset(dp, -1, sizeof(dp));
        memset(brr, 0, sizeof(brr));
        cout << "#" << t << " ";
        cin >> N;
        for (int i = 0; i < N; i++) cin >> arr[i];
        cin >> M;
        for (int i = 0; i < M; i++) cin >> brr[i];
        sort(brr, brr + 102, greater<int>());
        cout << play(0, 0, 0, 0) << "\n";
    }
    return 0;
}