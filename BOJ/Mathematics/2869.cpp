#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <functional>
#include <string>

using namespace std;
void fastIO();

int main()
{
	int A, B, V;
	int day = 0;

	cin >> A >> B >> V;

	day = (V - B - 1) / (A - B) + 1;
	cout << day;
}

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}