// https://www.acmicpc.net/problem/1946
#include <iostream>
#include <algorithm>
using namespace std;


int T, N;
int cnt_array[21];
pair<int,int> score[100000];
int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> score[j].first >> score[j].second;
		}

		sort(score, score + N); //first를 기준으로 오름차순으로 정렬


		int max_score = score[0].second;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (score[i].second <= max_score) {
				cnt++;
				max_score = score[i].second;
			}
		}

		cnt_array[i] = cnt;
		
	}

	for (int i = 0; i < T; i++) {
		cout << cnt_array[i]<<endl;
	}


	return 0;
} 