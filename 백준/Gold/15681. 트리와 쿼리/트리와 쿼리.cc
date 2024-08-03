#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<vector<int>> Connect;
vector<int> NumChilds;
vector<bool> Visited;

void dfs(int current)
{
    NumChilds[current] = 1;
    Visited[current] = true;

    for(auto child : Connect[current])
    {
        if(Visited[child]) continue;
        dfs(child);
        NumChilds[current] += NumChilds[child];
    }
}

int main()
{
    // 2:55

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> R >> Q;
    Connect.resize(N+1);
    NumChilds.resize(N+1);
    Visited.resize(N+1, false);

    for(int i = 0; i < N-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        Connect[u].push_back(v);
        Connect[v].push_back(u);
    }
        
    dfs(R);

    for(int i = 0; i < Q; ++i)
    {
        int query;
        cin >> query;

        cout << NumChilds[query] << '\n';
    }

    // 3:11
    return 0;
}