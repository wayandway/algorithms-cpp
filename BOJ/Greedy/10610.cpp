#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    string N;
    bool check = false;
    long long sum = 0;
    
    cin >> N;
 
    for (int i = 0; i < N.size(); i++) {
        if (!(N[i] - '0')) check = true;
        sum += ((long long)N[i] - 48);
    }
 
    if (sum % 3 != 0 || check == false) {
        cout << -1 << '\n';
    }
    else
    {
        sort(N.rbegin(), N.rend());
        cout << N;
    }
 
    return 0;
}
