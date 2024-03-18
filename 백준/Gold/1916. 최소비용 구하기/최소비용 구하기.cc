#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> cities;
const int INF = INT_MAX;

int dijkstra(int start, int destination)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> path(N+1, INF);

    q.push({0, start});
    path[start] = 0;

    while(!q.empty())
    {
        auto p = q.top(); q.pop();
        int node = p.second;
        int cost = p.first;
        if(node == destination) return cost;

        for(auto edge : cities[node])
        {
            int to = edge.first;
            int weight = edge.second;
            
            if(cost + weight < path[to])
            {
                q.push({cost + weight, to});
                path[to] = cost + weight;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    cities.resize(N+1);
    for(int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        cities[from].push_back({to, cost});
    }
    int start, destination;
    cin >> start >> destination;

    cout << dijkstra(start, destination);
    
    return 0;
}