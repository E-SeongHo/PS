#include <iostream>
#include <vector>

using namespace std;

int K, V, E;
vector<vector<int>> Edges;

bool dfs(int cur, int depth, vector<int>& mark)
{
    mark[cur] = depth+1;
    for(int node : Edges[cur])
    {   
        if(!mark[node]) 
        {
            if(!dfs(node, depth+1, mark)) return false;
        }

        if(mark[node] && mark[cur] % 2 == mark[node] % 2) return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> K;
    for(int k = 0; k < K; ++k)
    {
        cin >> V >> E;
        Edges.resize(0); Edges.resize(V+1);

        for(int e = 0; e < E; ++e)
        {
            int u, v;
            cin >> u >> v;
            Edges[u].push_back(v);
            Edges[v].push_back(u);
        }

        vector<int> mark(V+1, 0);
        
        bool flag = false;
        for(int i = 1; i < V+1; ++i)
        {
            if(!mark[i]) 
            {
                if(!dfs(i, 0, mark))
                {
                    flag = true;
                    break;
                }
            }
        }

        if(flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';

    }
    return 0;
}