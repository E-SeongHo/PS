#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> Partial;
vector<bool> Visited;
vector<bool> Discovered;

vector<int> VisitOrder;

bool Cycle = false;
void dfs(int cur)
{
    if(Cycle) return;

    Discovered[cur] = true;

    for(int neighbor : Partial[cur])
    {
        if(!Visited[neighbor] && Discovered[neighbor])
        {
            Cycle = true;
            return;
        }

        if(!Visited[neighbor]) dfs(neighbor);
    }

    Visited[cur] = true;
    VisitOrder.push_back(cur);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    Partial.resize(N+1);
    Visited.resize(N+1); Discovered.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int j = 0; j < n; ++j)
            cin >> v[j];

        for(int j = n-1; j > 0; --j)
            Partial[v[j]].push_back(v[j-1]);
    }

    for(int i = 1; i < N+1; ++i)
    {
        if(!Visited[i]) dfs(i);
    }

    if(Cycle) cout << 0;
    else
    {
        for(int vertex : VisitOrder)
        {
            cout << vertex << '\n';
        }
    }
    return 0;
}
