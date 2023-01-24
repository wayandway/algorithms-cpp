#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int dp[2002][10001] = {0};
struct knapsack{
  int weight;
  int cost; 
};

vector<knapsack> items;

int min(int a, int b){
  return a < b? a : b;
}

int max(int a, int b){
  return a > b? a : b;
}

void solve(){
  for(int i=1; i <= items.size(); i++){
    for(int j=1; j <= M; j++){
      dp[i][j] = dp[i-1][j];
      if(j - items[i-1].weight >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].weight] + items[i-1].cost);
    }
  }
}

void case_items(int v,int c,int k){
  for(int j = 0; k > 0; j++){
    int tmp = min(1 << j, k);
    items.push_back({v * tmp, c * tmp});
    k -= tmp;
  }
}

void input(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    int v, c, k;
    cin >> v >> c >> k;
    case_items(v,c,k);
   
  }
}

int main(void){
  ios::sync_with_stdio(false);       
  cin.tie(NULL); cout.tie(NULL);
  input();
  solve();
  cout << dp[items.size()][M] << "\n";
  return 0;
}