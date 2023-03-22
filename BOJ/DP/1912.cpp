#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100010];
int dp[100010]; 
int answer;



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    dp[1] = arr[1]; 
    
    for(int i=2;i<=n;i++){
        if(dp[i-1] > 0){ 
            dp[i] = dp[i-1] + arr[i]; 
        }
        else{ 
            dp[i] = arr[i]; 
        }
    }
    
    answer = dp[1];
    for(int i=2;i<=n;i++){
        if(answer < dp[i]) answer = dp[i]; 
    }
    
    cout << answer << '\n';
	
	return 0;
}