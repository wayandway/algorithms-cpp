#include <bits/stdc++.h>
using namespace std;

int n, num, answer = 9;

void dfs(int count, int currentNumber){
    if(count >= 9)  return;
    if(currentNumber == num){
        answer = min(answer, count);
        return;
    }

    int tempNumber = 0;
    for(int i = 0; i + count < 9; i++){
        tempNumber = tempNumber * 10 + n;
        dfs(count + 1 + i, currentNumber + tempNumber);
        dfs(count + 1 + i, currentNumber - tempNumber);
        dfs(count + 1 + i, currentNumber * tempNumber);
        dfs(count + 1 + i, currentNumber / tempNumber);
    }
}

int solution(int N, int number) {
    n = N;
    num = number;
    dfs(0, 0);
    if(answer == 9) return -1;
    return answer;
}