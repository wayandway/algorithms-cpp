#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

priority_queue <pair<int, int>> que;
int n = 0;
int num = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> num;
		if (num == 0) {
			if (que.size() == 0)
				cout << 0 << "\n";
			else {
				cout <<  que.top().first * que.top().second  << "\n";
				que.pop();
			}
		}
		else {
			if(num > 0)
				que.push(make_pair(-1 * abs(num),-1));
			else
				que.push(make_pair(-1 * abs(num), 1));
		}
	}
	return 0;
}