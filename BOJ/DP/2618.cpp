#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,w;
vector<pair<int,int> > p;
int store[1010][1010];
int police_store[1010][1010];

int calculate_distance(int police, int target, int start){

    int police_x,police_y,target_x,target_y;
    if(start == 1){
        police_x = 1;
        police_y = 1;
    }
    else if(start == 2){
        police_x = n;
        police_y = n;

    }
    else{
        police_x = p[police-1].first;
        police_y = p[police-1].second;
    }
    target_x = p[target-1].first;
    target_y = p[target-1].second;
    return abs(police_x-target_x) + abs(police_y-target_y);
}

int find_distance(int police1, int police2){
    if(police1 == w || police2 == w){
        return 0;
    }

    int tmp1, tmp2, move;

    move = max(police1, police2) + 1;
    if(store[police1][police2] != -1){
        return store[police1][police2];
    }
    if(police1 == 0){
        tmp1 = find_distance(move,police2) + calculate_distance(police1, move, 1);
    }
    else{
        tmp1 = find_distance(move,police2) + calculate_distance(police1, move, 0);
    }
    if(police2 == 0){
        tmp2 = find_distance(police1,move) + calculate_distance(police2, move, 2);
    }
    else{
        tmp2 = find_distance(police1,move) + calculate_distance(police2, move, 0);
    }

    store[police1][police2] = min(tmp1,tmp2);

    if(tmp1 < tmp2){
        police_store[police1][police2] = 1;
    }
    else{
        police_store[police1][police2] = 2;
    }
    return min(tmp1,tmp2);
}

int main(){
    int tmp1,tmp2;
    cin >> n;
    cin >> w;
    for(int i=0;i<w;i++){
        cin >> tmp1;
        cin >> tmp2;
        p.push_back(make_pair(tmp1,tmp2));
    }

    for(int i=0;i<1010;i++){
        for(int j=0;j<1010;j++){
            store[i][j] = -1;
            police_store[i][j] = -1;
        }
    }

    cout << find_distance(0,0) << endl;

    int x = 0;
    int y = 0;
    
    for(int i=0;i<w;i++){
        cout << police_store[x][y] << endl;
        if(police_store[x][y] == 1){
            x = i+1;
        }
        else{
            y = i+1;
        }
    }
}