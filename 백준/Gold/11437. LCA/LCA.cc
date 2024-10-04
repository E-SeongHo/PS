#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Parent;
vector<vector<int>> Edges;
vector<int> Depth;

void dfs(int cur, int dep)
{
    Depth[cur] = dep;

    for(int vertex : Edges[cur])
    {
        if(!Depth[vertex] && vertex != 1)
        {
            Parent[vertex] = cur;
            dfs(vertex, dep+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Parent.resize(N+1);
    Depth.resize(N+1);
    Edges.resize(N+1);

    for(int i = 0; i < N-1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;

        Edges[v1].push_back(v2);
        Edges[v2].push_back(v1);
    }

    dfs(1, 0);

    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;

        if(Depth[v1] > Depth[v2]) swap(v1, v2);
        while(Depth[v1] != Depth[v2])
        {
            v2 = Parent[v2];
        }

        while(v1 != v2)
        {
            v1 = Parent[v1];
            v2 = Parent[v2];
        }

        cout << v1 << '\n';
    }

    return 0;
}