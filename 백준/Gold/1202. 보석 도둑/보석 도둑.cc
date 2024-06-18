#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, M, V, C;
vector<pair<int, int>> Gems;
vector<int> Bags;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    Gems.resize(N);
    Bags.resize(K);

    for(int i = 0; i < N; i++)
    {
        cin >> M >> V;
        Gems[i] = {M, V};
    }    

    for(int i = 0; i < K; i++)
    {
        cin >> Bags[i];
    }

    sort(Gems.begin(), Gems.end());
    sort(Bags.begin(), Bags.end());

    priority_queue<int> pq;

    long long ret = 0;
    int ptr = 0;
    for(auto bag : Bags)
    {
        while(ptr < N && Gems[ptr].first <= bag)
        {
            pq.push(Gems[ptr++].second);
        }

        if(!pq.empty()) 
        {
            ret += pq.top(); pq.pop();
        }
    }

    cout << ret;

    return 0;
}