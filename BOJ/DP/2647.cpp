#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
int N, dp[101][101], hgt[101][101], last[101][101];
string S;
 
int dfs(int s, int e) {
    if (s == e - 1) {
        if (S[s] == S[e]) return 100000;
        hgt[s][e] = 1;
        return dp[s][e] = 3;
    }
    if (dp[s][e]) return dp[s][e];
 
    int ans = 1e9, comp;
    for (int i = s + 1; i < e - 1; i += 2) {
        comp = dfs(s, i) + dfs(i + 1, e);
        if (ans > comp) {
            ans = comp;
            hgt[s][e] = max(hgt[s][i], hgt[i + 1][e]);
            last[s][e] = i;
        }
    }
 
    if (S[s] != S[e] && s + 1 < e - 1) {
        comp = dfs(s + 1, e - 1) + (hgt[s + 1][e - 1] + 1) * 2 + e - s;
        if (ans > comp) {
            ans = comp;
            hgt[s][e] = hgt[s + 1][e - 1] + 1;
            last[s][e] = -1;
        }
    }
 
    return dp[s][e] = ans;
}
 
void traceback(int s, int e) {
    if (s >= e) return;
    if (s == e - 1) {
        cout << s << ' ' << e << '\n';
        return;
    }
    if (last[s][e] == -1) {
        cout << s << ' ' << e << '\n';
        traceback(s + 1, e - 1);
    }
    else {
        traceback(s, last[s][e]);
        traceback(last[s][e] + 1, e);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> N >> S;
    S.insert(S.begin(), '.');
    cout << dfs(1, N) << '\n';
    traceback(1, N);
 
    return 0;
}