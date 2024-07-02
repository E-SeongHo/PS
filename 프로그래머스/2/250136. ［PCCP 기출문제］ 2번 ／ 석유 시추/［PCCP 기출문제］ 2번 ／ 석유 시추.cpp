#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

int N, M;
vector<int> amounts;
vector<vector<bool>> visited;

void traverse(int y, int x, vector<vector<int>>& land)
{
    set<int> path_x;
    int aquire = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    
    while(!q.empty())
    {
        auto [cy, cx] = q.front(); q.pop();
        aquire ++;
        path_x.insert(cx);
        
        for(int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if(ny >= 0 && ny < N && nx >= 0 && nx < M)
            {
                if(!visited[ny][nx] && land[ny][nx] == 1)
                {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
    
    for(auto px : path_x)
    {
        amounts[px] += aquire;
    }
}

int solution(vector<vector<int>> land) {
    
    N = land.size();
    M = land[0].size();
    visited.resize(N, vector<bool>(M, false));
    amounts.resize(M);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(!visited[i][j] && land[i][j] == 1)
            {
                traverse(i, j, land);
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < M; i++)
    {
        answer = max(answer, amounts[i]);
    }
    return answer;
}