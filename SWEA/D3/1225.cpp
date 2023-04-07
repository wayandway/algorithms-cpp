#include <iostream>
#include <vector>

void solve(void);

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	solve();
}

std::vector<int> encrypt(std::vector<int>& plain)
{
	int idx = 0;
	int subtraction = 1;

	while (0 < plain[idx] - subtraction)
	{
		plain[idx] -= subtraction;
		idx = (idx + 1) % 8;
		subtraction = ((subtraction + 1) % 5) ? ((subtraction + 1) % 5) : 5;
	}
	plain[idx] = 0;

	std::vector<int> encryption(8);
	for (int i = 1; i <= 8; i++)
		encryption[i - 1] = plain[(idx + i) % 8];

	return encryption;
}

void solve(void)
{
	for (int t = 1; t <= 10; t++)
	{
		int test_case;
		std::cin >> test_case;

		std::vector<int> vec(8);
		for (int i = 0; i < 8; i++)
			std::cin >> vec[i];

		std::vector<int> answer = encrypt(vec);

		std::cout << "#" << test_case;
		for (auto& a : answer)
			std::cout << " " << a;
		std::cout << '\n';
	}
}