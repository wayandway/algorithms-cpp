#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1005][1005];

int main(){
	string a,b;
	int ans = 0;
	
	cin >> a >> b;
	
	for(int i=1;i<=a.size();i++)
		for(int j=1;j<=b.size();j++)
			if(a[i-1]==b[j-1])
				arr[i][j] = arr[i-1][j-1] + 1;
			else
				arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
	
	printf("%d",arr[a.size()][b.size()]);
	
	return 0;
}