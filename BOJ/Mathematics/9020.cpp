#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000

int arr[MAX + 1]{ 0, };

int main()
{
    for (int i = 2; i <= MAX; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i * i <= MAX; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        for (int j = i * i; j <= MAX; j += i)
        {
            arr[j] = 0;
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> prime;
        for (int i = 2; i <= n; i++)
        {
            if (arr[i] != 0)
            {
                prime.push_back(arr[i]);
            }
        }

        bool flag = false;
        for (int i = 0; i < prime.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (prime[i] + prime[j] == n)
                {
                    cout << prime[j] << ' ' << prime[i] << '\n';
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
    }
    return 0;
}