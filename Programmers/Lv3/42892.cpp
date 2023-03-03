#include <string>
#include <vector>

#include <algorithm>
#include <iostream>
using namespace std;

struct tree_str{
    int idx;
    int x;
    int y;
    tree_str *left;
    tree_str *right;
};

vector<tree_str> tree;
vector<vector<int>> answer(2);

bool way(vector<int>&a,vector<int>&b){
    if(a[1]==b[1]){
        return a[0]<b[0];
    }
    return a[1]>b[1];
}


void Make_Tree(tree_str *Root, tree_str* Child){
    if(Root->x > Child->x){
        if(Root->left == NULL){
            Root->left = Child;
            return;
        }
        Make_Tree(Root->left,Child);
    }
    else{
        if(Root->right == NULL){
            Root->right = Child;
            return;
        }
        Make_Tree(Root->right,Child);
    }
}

void pre(tree_str *Root){
    if(Root==NULL){
        return;
    }
    answer[0].push_back(Root->idx);
    pre(Root->left);
    pre(Root->right);
}

void post(tree_str *Root){
    if(Root==NULL){
        return;
    }
    post(Root->left);
    post(Root->right);
    answer[1].push_back(Root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    for(int i=0;i<nodeinfo.size();i++){
        nodeinfo[i].push_back(i+1);
    }
    
    sort(nodeinfo.begin(),nodeinfo.end(),way);
    
    for(vector<int> i : nodeinfo){
        int x =i[0];
        int y =i[1];
        int idx =i[2];
        tree.push_back({idx,x,y,0,0});
    }
    
    tree_str *Root = &tree[0];
    
    for(int i=1;i<tree.size();i++){
        Make_Tree(Root,&tree[i]);
    }
    
    pre(Root);
    post(Root);
    
    return answer;
}