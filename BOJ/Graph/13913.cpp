#include <iostream>
#include <queue>
#include <vector>
#include <stack>
 
using namespace std;
 
vector<int>vec(100001);  
bool visited[100001];  
queue<int> q;
int n, k, result_time, cnt, sec;
 
void hide_and_seek() {
    q.push(n);
    visited[n] = 1;
    sec = 1;
    result_time = 0;
 
    while (!q.empty()) {
        cnt = 0;
        for (int i = 0; i < sec; i++) {
            int now = q.front();
            q.pop();
            if (now == k)
                return;
 
            if (now - 1 >= 0 && visited[now - 1] == 0) {
                q.push(now - 1);
                visited[now - 1] = 1;
                vec[now - 1] = now;
                cnt++;
            }
            if (now + 1 <= 100000 && visited[now + 1] == 0) {
                q.push(now + 1);
                visited[now + 1] = 1;
                vec[now + 1] = now;
                cnt++;
            }
            if (now * 2 <= 100000 && visited[now * 2] == 0) {
                q.push(now * 2);
                visited[now * 2] = 1;
                vec[now * 2] = now;
                cnt++;
            }
        }
        sec = cnt;
        if (cnt != 0)
            result_time++;
    }
}
 
int main(void) {
    cin >> n >> k;
    for (int i = 0; i < 100001; i++)
        visited[i] = 0;
    hide_and_seek();
    cout << result_time << '\n';
 
    int now = k;
    int prev;
    stack<int> stk;
    while (now != n) {
        stk.push(now);
        prev = vec[now];
        now = prev;
    }
 
    cout << n << " ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
}