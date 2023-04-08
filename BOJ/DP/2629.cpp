#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

#define MAX 30

int marblenum, checknum;
vector <int> weight;
vector <int> marble;
bool DP[MAX + 1][MAX * 500 + 1] = { false, };

void preCalculate(int currentmarble, int currentWeight) {
	if (currentmarble > marblenum)
		return;
	if (DP[currentmarble][currentWeight] != 0)
		return;

	DP[currentmarble][currentWeight] = true;

	preCalculate(currentmarble + 1, currentWeight + weight[currentmarble]);
	preCalculate(currentmarble + 1, currentWeight);
	preCalculate(currentmarble + 1, abs(currentWeight - weight[currentmarble]));
}

int main(void) {
	cin >> marblenum;
	for (int i = 0; i < marblenum; i++) {
		int checkweight; cin >> checkweight;
		weight.push_back(checkweight);
	}

	cin >> checknum;
	for (int i = 0; i < checknum; i++) {
		int checkweight; cin >> checkweight;
		marble.push_back(checkweight);
	}
	preCalculate(0, 0);

	for (int i = 0; i < checknum; i++) {
		if (marble[i] > MAX * 500)
			cout << "N ";

		else if (DP[marblenum][marble[i]])
			cout << "Y ";
		else
			cout << "N ";
	}

	return 0;
}