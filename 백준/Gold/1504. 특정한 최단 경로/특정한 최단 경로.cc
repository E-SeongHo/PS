#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int V, E;
const long long INF = INT_MAX;

vector<vector<pair<int, int>>> adjList;

vector<long long> dijkstra(int start)
{
    vector<long long> costs(V+1, INF);
    costs[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        auto p = pq.top(); pq.pop();
        int vertex = p.second;
        int cost = p.first;

        for(int i = 0; i < adjList[vertex].size(); i++)
        {
            int weight = cost + adjList[vertex][i].second;
            int next = adjList[vertex][i].first;
            if(weight < costs[next])
            {
                pq.push({weight, next});
                costs[next] = weight;
            }
        }
    }

    return costs;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;
    adjList.resize(V+1);

    for(int i = 0; i < E; i++)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        adjList[n1].push_back({n2, w});
        adjList[n2].push_back({n1, w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<long long> v1Cost = dijkstra(v1);
    vector<long long> v2Cost = dijkstra(v2);

    long long path1 = v1Cost[1] + v2Cost[V];
    long long path2 = v2Cost[1] + v1Cost[V];

    long long path = min(path1, path2);

    if(path > INF || v1Cost[v2] == INF) cout << -1;
    else cout << path + v1Cost[v2];

    return 0;
}