#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
using namespace std;
typedef long long Long;
const Long MOD = 1000000007;
int slime(priority_queue<Long>& pq) {
	int ret = 1;

	while (pq.size() > 1) {
		Long a = -pq.top();
		pq.pop();
		Long b = -pq.top();
		pq.pop();
		Long combine = a * b;

		ret = combine % MOD * ret % MOD;
		pq.push(-combine);
	}
	return ret;
}
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int n;
		Long tmp;
		scanf("%d", &n);
		priority_queue<Long> pq;
		if (pq.size() == 1)
			printf("1\n");
		else {
			for (int i = 0; i < n; i++) {
				scanf("%lld", &tmp);
				pq.push(-tmp);
			}
			printf("%d\n", slime(pq));
		}
	}
}