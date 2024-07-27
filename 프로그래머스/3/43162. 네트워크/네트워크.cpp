#include <string>
#include <vector>

using namespace std;

vector<bool> Visited;

void dfs(vector<vector<int>>& computers, int current)
{
    Visited[current] = true;
    
    for(int i = 0; i < computers.size(); i++)
    {
        if(computers[current][i] && !Visited[i])
        {
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    // 10:59
   
    Visited.resize(computers.size(), false);
    int cnt = 0;
    for(int i = 0; i < computers.size(); i++)
    {
        if(!Visited[i])
        {
            dfs(computers, i);
            cnt++;
        }
    }
    
    // 11:07
    return cnt;
}