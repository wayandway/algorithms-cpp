#include <iostream>
#include <cstring>
#include <queue>
#define MAX 100001

using namespace std;

int subin, bro;
int cache[MAX];
struct Node
{
    int idx, dist;
    bool operator<(const Node &b) const
    {
        return idx > b.idx;
    }
};

int getMinTime()
{
    for (int i = 0; i < MAX; i++)
        cache[i] = MAX;
    cache[subin] = 0;
    priority_queue<Node> pq;
    pq.push({subin, 0});

    while (!pq.empty())
    {
        Node curr = pq.top();
        int idx = curr.idx, dist = curr.dist;
        pq.pop();
        if (dist > cache[idx])
            continue;

        int nIdx, nDist;
        nIdx = idx * 2, nDist = dist;
        if (nIdx < MAX && nDist < cache[nIdx])
        {
            cache[nIdx] = nDist;
            pq.push({nIdx, nDist});
        }
        nIdx = idx - 1, nDist = dist + 1;
        if (nIdx >= 0 && nDist < cache[nIdx])
        {
            cache[nIdx] = nDist;
            pq.push({nIdx, nDist});
        }
        nIdx = idx + 1, nDist = dist + 1;
        if (nIdx < MAX && nDist < cache[nIdx])
        {
            cache[nIdx] = nDist;
            pq.push({nIdx, nDist});
        }
    }

    return cache[bro];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> subin >> bro;

    if (subin >= bro)
    {
        cout << subin - bro << '\n';
        return 0;
    }

    cout << getMinTime();

    return 0;
}