#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using edge = tuple<int, int, int>;
const int INF = 987654321;

bool bellman_ford(vector<int>& paths, vector<edge>& edges)
{
    paths[1] = 0;
    for(int i = 0; i < paths.size()-2; ++i) // N-1
    {
        for(auto e : edges)
        {
            int n1 = get<0>(e);
            int n2 = get<1>(e);
            int w = get<2>(e);
            
            if(paths[n1] + w < paths[n2])
            {
                paths[n2] = paths[n1] + w;
            }
        }
    }

    for(auto e : edges)
    {
        int n1 = get<0>(e);
        int n2 = get<1>(e);
        int w = get<2>(e);
        
        if(paths[n1] + w < paths[n2])
        {   
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC; // 1 <= TC <= 5

    cin >> TC;
    for(int t = 0; t < TC; ++t)
    {
        int N, M, W; // |V|, |undir E|, |neg E|
        cin >> N >> M >> W;

        vector<int> paths(N+1);
        fill(paths.begin(), paths.end(), INF);

        vector<edge> edges;
        edges.reserve(2*N + M);
        // positive undirected edges
        for(int i = 0; i < M; ++i)
        {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }
        // negative directed edges (wormholes)
        for(int i = 0; i < W; ++i)
        {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, -T});
        }

        bellman_ford(paths, edges) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}