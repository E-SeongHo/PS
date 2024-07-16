#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visited;
vector<vector<int>> edges;
int N;

int ans = 9999;
int cnt = 0;
int dfs(int current)
{
    visited[current] = true;
    cnt++;
    
    int cnt_until = cnt;
    for(auto v : edges[current])
    {
        if(!visited[v]) 
        {
            dfs(v);
            int childs = cnt - cnt_until;
            ans = min(ans, abs(N-childs - childs));
            cnt_until = cnt;            
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    
    vector<int> in(n+1);
    N = n;
    visited.resize(n+1);
    edges.resize(n+1);
    
    for(auto edge : wires)
    {
        edges[edge[0]].push_back(edge[1]);
        edges[edge[1]].push_back(edge[0]);
        
        in[edge[0]]++;
        in[edge[1]]++;
    }
    
    // find any root
    int root = -1;
    for(int i = 1; i < n+1; i++)
    {
        if(in[i] == 1)
        {
            root = i;
            break;
        }
    }
    
    dfs(root);
    
    return ans;
}