// https://www.acmicpc.net/problem/2839
#include <iostream>

using namespace std;
int n, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cnt = 0;

	while (n >= 0) {
		if (n % 5 == 0) {
			cnt += (n / 5);
			cout << cnt << '\n';
			return 0;
		}
		else {
			cnt ++;
			n -= 3;
		}
	}
    
	cout << -1 << '\n';

}