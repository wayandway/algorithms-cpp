// https://www.acmicpc.net/problem/1201
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(503);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    if(n >= m + k - 1 && n <= m * k) {
        for(int i = 0; i < n; ++i) v[i] = i + 1;
        int index = 0;
        for(int i = 1; i <= m; ++i) {
            int temp = min(index + k, n - m + i);
            reverse(v.begin() + index, v.begin() + temp);
            index = temp;
        }
        for(int i = 0; i < n; ++i) cout << v[i] << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}