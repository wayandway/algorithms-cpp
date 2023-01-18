#include<iostream>
using namespace std;
 
int prices[1000000], max_price[1000000];
 
int max(int N){
    int idx = N - 1;
    for(int i = N - 1; i >= 0; i--){
        if (*(prices + idx) < *(prices + i))
            idx = i;
        max_price[i] = idx;
    }
}
 
int main(int argc, char** argv){
    int i, test_case, T, N;
    cin>> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        long int num_stock = 0, balance = 0;
        for (i = 0; i < N; i++) scanf("%d", prices+i);
        max(N);
        int idx = max_price[0];
         
        for (i = 0; i < N; i++) {
            if (idx <= i) {
                idx = max_price[i + 1];
                balance +=  *(prices + i) * num_stock;
                num_stock = 0;
            }
            else {
                num_stock++;
                balance -= *(prices + i);
            }
        }
        if(num_stock) balance += prices[i] * num_stock;
        printf("#%d %ld\n", test_case, balance);
    }
    return 0;
}