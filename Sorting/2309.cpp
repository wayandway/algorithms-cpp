#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
vector<int> childs; 
vector<int> tmp; 
 
void find(int depth){
 
    if (tmp.size() == 7 &&  accumulate(tmp.begin(), tmp.end(), 0) == 100){
        sort(tmp.begin(), tmp.end());
        for (size_t i = 0; i < tmp.size(); i++){
            cout << tmp[i] << endl;
        }
        exit(0); 
        return;
    }
    if (depth >= 9) 
        return;
 
    tmp.push_back(childs[depth]); 
    find(depth+1);
    tmp.pop_back();
    find(depth+1);
}
 
int main(){
    int c;
    for (size_t i = 0; i < 9; i++){
        cin >> c;
        childs.push_back(c);
    }
 
    find(0);
    return 0;
}
