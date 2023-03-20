#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long result;
int A, B;
int N;

int divCon(int num);

long long power(long long x, long long K) {
    long long result = 1;
    while (K != 0) {
        if (K & 1) result = (result * x) % (A + B);
        x = (x * x) % (A + B);
        K = (K >> 1);
    }
    return result;
}

int main() {
    int T, K;
    string input;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> A >> B >> K;
        result = 0;

        if (K == 1) {
            if (A < B) result = min(2 * A, B - A);
            else result = min(2 * B, A - B);
        }
        else result = divCon(K);

        cout << '#' << test_case << ' ' << result << "\n";

    }
    return 0;
}

int divCon(int K) {
    long long re1 = (power(2, K) * A) % (A + B);
    return re1 < (A+B -re1)? re1 : (A+B-re1);
}