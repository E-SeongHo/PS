#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Populations;
vector<vector<int>> Connections;
vector<int> SelectedSum;
vector<int> UnSelectedSum;

int dfs(int parent, int current, bool selected)
{
    if(selected && SelectedSum[current]) return SelectedSum[current];
    if(!selected && UnSelectedSum[current]) return UnSelectedSum[current];

    for(int node : Connections[current])
    {
        if(node == parent) continue;

        dfs(current, node, true);
        dfs(current, node, false);
    }

    if(selected)
    {
        for(int node : Connections[current])
        {
            if(node == parent) continue;

            SelectedSum[current] += UnSelectedSum[node];
        }
        SelectedSum[current] += Populations[current];
        return SelectedSum[current];
    }
    else
    {
        for(int node : Connections[current])
        {
            if(node == parent) continue;

            UnSelectedSum[current] += max(SelectedSum[node], UnSelectedSum[node]);
        }
        return UnSelectedSum[current];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    Populations.resize(N+1);
    Connections.resize(N+1);
    SelectedSum.resize(N+1, 0);
    UnSelectedSum.resize(N+1, 0);

    for(int i = 1; i < N+1; ++i)
        cin >> Populations[i];

    for(int i = 0; i < N-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        Connections[a].push_back(b);
        Connections[b].push_back(a);
    }


    int ans = max(dfs(0, 1, true), dfs(0, 1, false));

    cout << ans;

    return 0;
}