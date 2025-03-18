#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> Edges;
vector<vector<int>> ReversedEdges;
vector<int> WinCnt;
vector<int> LoseCnt;

int dfs(int cur, vector<vector<int>>& edges, vector<bool>& visited)
{
    visited[cur] = true;
    
    int cnt = 0;
    for(int neighbor : edges[cur])
    {
        if(visited[neighbor]) continue;
        
        cnt += dfs(neighbor, edges, visited);
    }
    
    return cnt + 1;
}

int solution(int n, vector<vector<int>> results) {
    
    int answer = 0;

    Edges.resize(n+1);
    ReversedEdges.resize(n+1);
    
    for(auto result : results)
    {
        Edges[result[0]].push_back(result[1]);
        ReversedEdges[result[1]].push_back(result[0]);
    }
    
    WinCnt.resize(n+1);
    LoseCnt.resize(n+1);
    
    for(int i = 1; i <= n; i++)
    {
        vector<bool> visited(n+1, false);
        WinCnt[i] = dfs(i, Edges, visited)-1;
    }

    for(int i = 1; i <= n; i++)
    {
        vector<bool> visited(n+1, false);
        LoseCnt[i] = dfs(i, ReversedEdges, visited)-1;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(WinCnt[i] + LoseCnt[i] == n-1) answer++;
    }
    
    return answer;
}