#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;

int n;
int memo[3001];
int sum[3001][3001];
pair<int,int> chk[3001];

int dp(int x) {
   if(x == n + 1) return 0;
   int &ret = memo[x];
   if(ret != -1) return ret;
   ret = 123456789;
   for(int i = x; i <= n; i++) {
       int in = sum[i][i] - sum[x - 1][i] - sum[i][x - 1] + sum[x - 1][x - 1];
       int out = sum[i][n] - sum[i][i] - sum[x - 1][n] + sum[x - 1][i];
       in = ((i - x + 1) * (i - x) - in) / 2;
       if(ret > in + out + dp(i + 1)) chk[x] = {i, i - x + 1};
       ret = min(ret, in + out + dp(i + 1));
   }
   return ret;
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin >> n;
   for(int i = 1; i <= n; i++) {
       int x; cin >> x;
       while(x) {
           sum[i][x] = 1;
           cin >> x;
       }
   }
   for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= n; j++) {
           sum[i][j] = sum[i][j - 1] + sum[i][j];
       }
   }
   for(int i = 1; i <= n; i++) {1
       for(int j = 1; j <= n; j++) {
           sum[i][j] = sum[i - 1][j] + sum[i][j];
       }
   }
   memset(memo, -1, sizeof(memo));
   cout << dp(1) << "\n";
   vector<int> ans;
   for(int cur = 1; cur <= n; cur = chk[cur].X + 1) {
       ans.push_back(chk[cur].Y);
   }
   cout << ans.size() << " ";
   for(int i : ans) cout << i << " ";
}