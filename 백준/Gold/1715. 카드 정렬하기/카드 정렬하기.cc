#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> PQ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        PQ.push(n);
    }

    long long sum = 0;
    while(PQ.size() != 1)
    {
        int a = PQ.top(); PQ.pop();
        int b = PQ.top(); PQ.pop();

        sum += a+b;
        PQ.push(a+b);
    }

    cout << sum;

    return 0;
}