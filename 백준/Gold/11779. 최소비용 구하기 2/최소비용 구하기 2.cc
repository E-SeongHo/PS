#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> Path;

void dijkstra(int start, int end)
{
    using tup = tuple<long long, int, int>;
    priority_queue<tup, vector<tup>, greater<tup>> pq;

    long long inf = numeric_limits<long long>::max();
    vector<pair<long long, int>> visited(N+1, {inf, -1});

    pq.push({0, start, -1});
    visited[start] = {0, -1};

    while(!pq.empty())
    {
        auto [cost, node, prev] = pq.top(); pq.pop();

        if(node == end) break;
        if(visited[node].first < cost) continue; 

        for(auto [next, weight] : Path[node])
        {
            long long new_cost = cost + weight;

            if(new_cost < visited[next].first)
            {
                visited[next] = {new_cost, node};
                pq.push({new_cost, next, node});
            }
        }
    }

    int current = end;
    vector<int> route;

    while(visited[current].second != -1)
    {
        route.push_back(current);
        current = visited[current].second;
    }
    route.push_back(current);

    cout << visited[end].first << '\n';
    cout << route.size() << '\n';
    for(auto it = route.rbegin(); it != route.rend(); ++it)
    {
        cout << *it << ' ';
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    Path.resize(N+1);

    for(int i = 0; i < M; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        Path[from].push_back({to, weight});
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start, end);

    return 0;
}