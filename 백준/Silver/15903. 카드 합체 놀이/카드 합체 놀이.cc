#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int N, M;
priority_queue<long long, vector<long long>, greater<long long>> PQ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    // O(NlogN)
    for(int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        PQ.push(n);
    }

    // O(4MlogN)
    for(int i = 0; i < M; ++i)
    {
        long long a = PQ.top(); PQ.pop();
        long long b = PQ.top(); PQ.pop();

        PQ.push(a+b);
        PQ.push(a+b);
    }

    // O(NlogN)
    long long sum = 0;
    while(!PQ.empty())
    {
        sum += PQ.top(); PQ.pop();
    }

    cout << sum;

    return 0;
}
