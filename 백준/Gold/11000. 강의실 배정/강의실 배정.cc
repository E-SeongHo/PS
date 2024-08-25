#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, S, T;
vector<pair<int, int>> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> S >> T;
        V[i] = {S, T};
    }

    sort(V.begin(), V.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto v : V)
    {
        if(!pq.empty() && pq.top() <= v.first)
        {
            pq.pop();
            pq.push(v.second);
        }
        else
        {
            pq.push(v.second);
        }
    }

    cout << pq.size();
    return 0;
}