#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<int> Wants;
vector<vector<int>> Cycles;

void dfs(int cur, vector<int>& prev, vector<bool>& discovered, vector<bool>& visited)
{
    if(discovered[cur] && !visited[cur])
    {
        vector<int> cycle;
        int tmp = prev[cur];
        while(tmp != cur)
        {
            cycle.push_back(tmp);
            tmp = prev[tmp];
        }
        cycle.push_back(cur);

        Cycles.push_back(cycle);
        return;
    }

    discovered[cur] = true;
    if(!visited[Wants[cur]])
    {
        prev[Wants[cur]] = cur;
        dfs(Wants[cur], prev, discovered, visited);
    }

    visited[cur] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;
        Wants.resize(0); Wants.resize(N+1);
        Cycles.resize(0);

        for(int i = 1; i < N+1; ++i)
            cin >> Wants[i];

        vector<bool> visited(N+1, false);
        vector<bool> discovered(N+1, false);
        vector<int> prev(N+1, -1);
        for(int i = 1; i < N+1; ++i)
        {
            if(!visited[i]) 
            {
                dfs(i, prev, discovered, visited);
            }
        }

        int ans = N;
        for(vector<int>& cycle : Cycles)
        {
            ans -= cycle.size();
        }
        
        cout << ans << '\n';
    }
    return 0;
}
