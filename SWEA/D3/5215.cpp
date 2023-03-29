#include <iostream>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define MAX 21

int total, max_cal;
int high_cal = 0;
int high_score = 0;

typedef struct data {
    int score;
    int cal;
}Data;

Data food[MAX];
bool visit[MAX];

void solve(int index, int score, int sum_cal) {
    if (sum_cal > max_cal) return;

    high_score = high_score > score ? high_score : score;

    for (int i = index + 1; i < total; i++) {
        if (!visit[i]) {
            visit[i] = true;
            solve(i, score + food[i].score, sum_cal+food[i].cal);
            visit[i] = false;
        }
    }
}
int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        memset(visit, 0, sizeof visit);
        cin >> total >> max_cal;
        for (int i = 0; i < total; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            food[i] = { temp1, temp2 };
        }
        for (int i = 0; i < total; i++) {
            visit[i] = true;
            solve(i, food[i].score, food[i].cal);
            visit[i] = false;
        }
        cout << "#"<<t<<" "<<high_score<<endl;
        high_score = 0; high_cal = 0;
    }
}