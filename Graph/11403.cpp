#include <iostream>
#include <string.h>
using namespace std;
 
int arr[100][100]={0};
int visited[100]={0};
int n;
 
void dfs(int j){
    for(int k=0;k<n;k++){
        if(arr[j][k] && !visited[k]){
            visited[k]++;
            dfs(k);
        }
    }
}
int main(){
    
    cin>>n;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    
    for(int i=0;i<n;i++){
        memset(visited,0,sizeof(visited));
        dfs(i);
        
        for(int j=0;j<n;j++){
            if(visited[j])
                arr[i][j]=1;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        
        cout<<endl;
    }
    return 0;
}
