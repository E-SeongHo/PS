#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> Edges;
vector<bool> Discovered;
vector<bool> Visited;
vector<int> Prev;

vector<bool> Cycle;

bool flag = false;
void dfs(int cur)
{
    if(Discovered[cur] && !Visited[cur] && !flag)
    {
        flag = true;
        // cout << "detect cycle" << endl;
        int tmp = Prev[cur];
        while(tmp != cur)
        {
            //cout << tmp << " -> ";
            Cycle[tmp] = true;
            tmp = Prev[tmp];
        }
        //cout << tmp << endl;
        Cycle[tmp] = true;
        return;
    }

    Discovered[cur] = true;

    for(int vertex : Edges[cur])
    {
        if(vertex == Prev[cur]) continue;
        if(Visited[vertex]) continue;

        Prev[vertex] = cur;
        dfs(vertex);
    }

    Visited[cur] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    Edges.resize(N+1);
    Discovered.resize(N+1, false);
    Visited.resize(N+1, false);
    Prev.resize(N+1, -1);

    for(int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        Edges[a].push_back(b);
        Edges[b].push_back(a);
    }

    Cycle.resize(N+1);
    for(int i = 1; i < N+1; ++i)
    {
        if(!Visited[i]) dfs(i);
    }

    vector<int> ans(N+1, 0);

    for(int i = 1; i < N+1; ++i)
    {
        if(Cycle[i]) continue;

        vector<bool> visited(N+1, false);
        queue<pair<int, int>> q;
        visited[i] = true;
        q.push({i, 0});
        
        while(!q.empty())
        {
            auto [cur, dist] = q.front(); q.pop();
            if(Cycle[cur]) 
            {
                ans[i] = dist;
                break;
            }

            for(int neighbor : Edges[cur])
            {
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push({neighbor, dist+1});
                }
            }
        }
    }

    for(int i = 1; i < N+1; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
