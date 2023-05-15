#include <iostream>
#include <cmath>
#include <cctype>
 
using namespace std;
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int test;
    cin>>test;
 
    for(int i=0; i<test; i++){
        double n,m,a;
        cin>>n>>m;
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i<j){
                    a = ((i*i+j*j+m)/(i*j));
                    if(abs(a - (int)a < 1e-12)){
                        cnt++;    
                    }
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}