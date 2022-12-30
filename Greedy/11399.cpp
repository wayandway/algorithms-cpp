// https://www.acmicpc.net/problem/11399
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
    int N;
    scanf("%d", &N);
 
    int* arr = new int[N];
 
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
 
    sort(arr, arr + N);
 
    int time = 0, tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += arr[i];
        time += tmp;
    }
    printf("%d\n", time);
    return 0;
}