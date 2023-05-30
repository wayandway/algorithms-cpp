#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
 
#define INF 987654321
#define MAX 16
int N;
int W[MAX][MAX];
int dpCost[MAX][1<<MAX];   
int allVisitBit;
 
int DFStravel(int cur_node, int visited_bit){   
    
    if(visited_bit == allVisitBit){            
        if(W[cur_node][0]==0) return INF;   
        else return W[cur_node][0];         
    }
    
    if(dpCost[cur_node][visited_bit] != -1 ) return dpCost[cur_node][visited_bit];
    
    dpCost[cur_node][visited_bit] = INF;
    for(int i = 0; i<N; i++){
        
        if(W[cur_node][i] == 0) continue;  
        if((visited_bit) & (1<<i)) continue;  
        
      
        dpCost[cur_node][visited_bit] = min(dpCost[cur_node][visited_bit],
                                            W[cur_node][i] + DFStravel(i, visited_bit|1<<i));
    }
    return dpCost[cur_node][visited_bit];
}
 
 
 
int main(){
    
    cin >> N;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> W[i][j];
        }
    }
    
    allVisitBit = (1<<N) - 1;       
    memset(dpCost, -1, sizeof(dpCost));
    
    int ans = DFStravel(0,1); 
    
    cout << ans;
    
    return 0;
}