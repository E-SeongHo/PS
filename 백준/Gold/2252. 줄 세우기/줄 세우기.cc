#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> Graph;

vector<bool> Visited;
vector<int> Order;

void dfs(int current)
{
    for(auto v : Graph[current])
    {
        if(!Visited[v])
        {
            dfs(v);
        }
    }

    Visited[current] = true;
    Order.push_back(current);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    Graph.resize(N+1);

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
    }

    Visited.resize(N+1, false);

    for(int i = 1; i < N+1; i++)
    {
        if(!Visited[i]) dfs(i);
    }

    for(auto it = Order.rbegin(); it != Order.rend(); ++it)
    {
        cout << *it << ' ';
    }

    return 0;
}