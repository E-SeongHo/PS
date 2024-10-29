#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> Edges;
vector<bool> OnStack;
vector<bool> Visited;
vector<int> Prev;


vector<bool> Cycle;
bool cycle_detected_flag = false;

void dfs(int cur)
{
	Visited[cur] = true;
	OnStack[cur] = true;

	for(int neighbor : Edges[cur])
	{
		//if(cycle_detected_flag) return;
		if(neighbor == Prev[cur]) continue;
		
		if(!Visited[neighbor])
		{
			Prev[neighbor] = cur;
			dfs(neighbor);
		}
		else if(OnStack[neighbor])
		{
			cycle_detected_flag = true;
			
			int vertex = cur;
			while(vertex != neighbor)
			{
				Cycle[vertex] = true;
				vertex = Prev[vertex];
			}
            Cycle[vertex] = true;
		}	
	}

	OnStack[cur] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    Edges.resize(N+1);
    OnStack.resize(N+1, false);
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
    int components = 0;
    dfs(1);

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
