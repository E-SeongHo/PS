#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, R;
vector<pair<int, vector<pair<int, int>>>> Path;

int dijkstra(int start)
{
    vector<int> visited(N+1, 99999999);
    visited[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        auto [cost, vertex] = pq.top(); pq.pop();

        if(visited[vertex] < cost) continue;

        for(auto [dest, weight] : Path[vertex].second)
        {
            int new_cost = cost + weight;
            if(new_cost < visited[dest])
            {
                visited[dest] = new_cost;
                pq.push({new_cost, dest});
            }
        }
    }

    int ret = 0;
    for(int i = 1; i < visited.size(); i++)
    {
        if(visited[i] <= M) ret += Path[i].first;
    }
    
    return ret;
}

int main()
{
    cin >> N >> M >> R;

    Path.resize(N+1);
    for(int i = 1; i < N+1; i++)
    {
        cin >> Path[i].first;
    }

    for(int i = 0; i < R; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;

        Path[a].second.push_back({b, l});
        Path[b].second.push_back({a, l});
    }

    int res = -1;
    for(int i = 1; i < N+1; i++)
    {
        res = max(res, dijkstra(i));
    }

    cout << res;

    return 0;
}