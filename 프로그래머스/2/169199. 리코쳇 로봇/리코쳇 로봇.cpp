#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    // 12:15
    
    vector<int> dx = {-1, +1, 0, 0};
    vector<int> dy = {0, 0, -1, +1};
    
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    int start_y, start_x;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 'R')
            {
                start_y = i;
                start_x = j;
                board[i][j] = '.';
            }
        }
    }
    
    queue<tuple<int, int, int>> q;
    q.push({start_y, start_x, 0});
    visited[start_y][start_x] = true;
    
    while(!q.empty())
    {
        auto [y, x, cost] = q.front(); q.pop();
        if(board[y][x] == 'G') return cost;
        
        for(int i = 0; i < 4; i++)
        {
            int ny = y; 
            int nx = x;
            while(ny >= 0 && ny < m && nx >= 0 && nx < n && board[ny][nx] != 'D')
            {
                ny += dy[i];
                nx += dx[i];
            }
            ny -= dy[i];
            nx -= dx[i];
            
            if(!visited[ny][nx])
            {
                q.push({ny, nx, cost+1});
                visited[ny][nx] = true;
            }
        }
    }

    //12:37
    return -1;
}