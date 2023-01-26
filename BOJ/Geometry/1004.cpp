#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

void solve(void);

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int test_case;
	std::cin >> test_case;
	for (int t = 0; t < test_case; t++)
		solve();
}

double distance(std::pair<int, int> a, std::pair<int, int> b)
{
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void solve(void)
{
	std::pair<int, int> start, end;
	std::cin >> start.first >> start.second >> end.first >> end.second;

	int n;
	std::cin >> n;
	
	std::vector<std::pair<int, std::pair<int, int>>> galaxy(n);
	for (int i = 0; i < n; i++)
	{
		int x, y, r;
		std::cin >> x >> y >> r;
		galaxy[i] = std::make_pair(r, std::make_pair(x, y));
	}
	std::sort(galaxy.begin(), galaxy.end());

	std::vector<bool> start_list(n), end_list(n);
	for (int i = 0; i < n; i++)
	{
		if (distance(start, galaxy[i].second) < galaxy[i].first)
			start_list[i] = true;
		if (distance(end, galaxy[i].second) < galaxy[i].first)
			end_list[i] = true;
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (start_list[i] && end_list[i])
			break;
		if (start_list[i] || end_list[i])
			answer++;
	}
	std::cout << answer << '\n';
}