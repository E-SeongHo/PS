#include <iostream>
#include <vector>

using namespace std;

int T, N;

void dfs(int cur, vector<bool>& visited, vector<vector<int>>& edge, vector<int>& order)
{
    if(cur == 0) return;
    visited[cur] = true;

    for(int n : edge[cur])
    {
        if(n != cur && !visited[n])
        {
            dfs(n, visited, edge, order);
        }
    }

    order.push_back(cur);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;
        vector<vector<int>> edge(N+1);
        vector<vector<int>> reverse(N+1);

        for(int i = 1; i < N+1; ++i)
        {
            int n;
            cin >> n;
            edge[i].push_back(n);
            reverse[n].push_back(i);
        }

        vector<bool> visited(N+1, false);
        vector<int> order;
        for(int i = 1; i < N+1; ++i)
        {
            if(visited[i]) continue;
            dfs(i, visited, edge, order);
        }

        vector<vector<int>> scc;
        fill(visited.begin(), visited.end(), false);

        for(auto it = order.rbegin(); it != order.rend(); ++it)
        {
            vector<int> tmp_order;
            if(visited[*it]) continue;

            dfs(*it, visited, reverse, tmp_order);

            scc.push_back(tmp_order);
        }

        int cnt = 0;
        for(vector<int>& c : scc)
        {
            if(c.size() == 1)
            {
                if(edge[c[0]][0] != c[0]) cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
