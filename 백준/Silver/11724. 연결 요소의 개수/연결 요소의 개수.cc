#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> visited;
vector<vector<int>> graph;

void DFS(int vertex)
{
    visited[vertex] = true;
    for(auto v : graph[vertex])
    {
        if(!visited[v]) DFS(v);
    }
}

int main()
{
    cin >> N >> M;
    visited.resize(N+1);
    graph.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    int cnt = 0;
    for(int i = 1; i < N+1; ++i)
    {
        if(visited[i]) continue;

        DFS(i);
        cnt++;
    }

    cout << cnt;

    return 0;
}
