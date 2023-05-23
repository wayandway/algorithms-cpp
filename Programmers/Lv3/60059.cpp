// 2020 KAKAO BLIND RECRUIT
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int lockZeroCount = 0;
int N = 0;
int M = 0;
vector<vector<int>> board(80, vector<int>(80, 1));
vector<vector<vector<int>>> keys(4, vector<vector<int>>(20, vector<int>(20, 0)));

void rotateKey(int current){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            keys[current][i][j] = keys[current - 1][M - j - 1][i];
        }
    }
}

bool dfs(int x, int y){
    int range[2] = {M - 1, N + M - 2};
    
    for(int i = 0; i < 4; i++){
        int count = 0;
        bool keep = true;
        
        for(int j = 0; j < M; j++){
            for(int k = 0; k < M; k++){
                if(board[x + j][y + k] && keys[i][j][k]){
                    if(x + j >= range[0] && x + j <= range[1] && y + k >= range[0] && y + k <= range[1]){
                        keep = false;
                        break;
                    }
                    continue;
                }
                
                if(!board[x + j][y + k] && keys[i][j][k]){
                    count++;
                }
            }
            if(!keep){
                break;
            }
        }
        
        if(count == lockZeroCount){
            return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    N = lock.size();
    M = key.size();
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(lock[i][j] == 0){
                lockZeroCount++;
                board[M - 1 + i][M - 1 + j] = lock[i][j];
            }
        }
    }
    
    keys[0] = key;
    
    for(int i = 1; i < 4; i++){
        rotateKey(i);
    }
    
    for(int i = 0; i < N + M - 1; i++){
        for(int j = 0; j < N + M - 1; j++){
            if(dfs(i, j)){
                return true;
            }
        }
    }
    
    return false;
}