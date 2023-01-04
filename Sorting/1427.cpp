// https://www.acmicpc.net/problem/1427
#include <iostream>
#include <vector>
#include <algorithm> //sort 사용 
#include <functional> //greater 사용
using namespace std;
 
//1427 - 소트인사이드
int main() {
    string str; 
    char ch;
    vector<char> vec;
    cin >> str;
    for (unsigned i = 0; i < str.size(); i++) {
        vec.push_back(str[i]);
    }
    sort(vec.begin(), vec.end(), greater<char>());
    for (char elem : vec)
        cout << elem ;
}
