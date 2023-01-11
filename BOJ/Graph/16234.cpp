// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility> 
#include <tuple>
#include <stack>
#define ll long long
#define INF 1e9
using namespace std;

int n,L,R;
int map[52][52];
int open[52][52];
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};
int day = 0;
int unions = 0;
vector<int> avgs;

bool needMove() {
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			for(int d=0;d<4;++d) {
				int ni,nj;

				ni = i+dr[d];
				nj = j+dc[d];

				int home = map[i][j];
				int adj = map[ni][nj];
				if(L <= abs(home-adj) && abs(home-adj) <= R) {
					return true;
				}		
			}
		}
	}

	return false;
}

void bfs(int r, int c) {
	int countries = 1;
	int population = map[r][c];

	queue<pair<int,int> > q;
	q.push(make_pair(r,c));
	open[r][c] = unions;

	while(!q.empty()) {
		pair<int,int> p = q.front();
		q.pop();

		r = p.first;
		c = p.second;

		for(int d=0;d<4;++d) {
			int nr,nc;
			nr = r+dr[d];
			nc = c+dc[d];

			if(open[nr][nc]) {
				continue;
			}

			int home = map[r][c];
			int adj = map[nr][nc];
			if(L <= abs(home-adj) && abs(home-adj) <= R) {
				open[nr][nc] = unions;
				countries++;
				population += map[nr][nc];
				q.push(make_pair(nr,nc));
			}
		}
	}

	avgs.push_back(population / countries);

	return;
}

void sol() {

	while(true) {
		memset(open,0,sizeof(open));
		if(!needMove()) {
			break;
		}

		day++;
		unions = 0;
		avgs.clear();
		avgs.push_back(-1);

		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) {
				if(!open[i][j]) {
					for(int d=0;d<4;++d) {
						int ni,nj;

						ni = i+dr[d];
						nj = j+dc[d];

						int home = map[i][j];
						int adj = map[ni][nj];
						if(L <= abs(home-adj) &&  abs(home-adj) <= R) {
							if(!open[ni][nj]) {
								unions++; 
								bfs(i,j);
							}
						}
					}
				}
			}
		}

		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) {
				if(open[i][j]) {
					int unionNum = open[i][j];
					map[i][j] = avgs[unionNum];
				}
			}
		}

	}
	
	return;
}

int main(void) {

	scanf("%d%d%d", &n,&L,&R);
	for(int i=0;i<52;++i) {
		for(int j=0;j<52;++j) {
			map[i][j] = INF;
		}
	}

	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			scanf("%d", &map[i][j]);
		}
	}

	sol();
	printf("%d\n", day);
	
	return 0;
}