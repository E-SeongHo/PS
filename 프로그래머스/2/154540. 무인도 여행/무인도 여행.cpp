#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) 
{
    // 12:40
    
    vector<int> dy = {-1, +1, 0, 0};
    vector<int> dx = {0, 0, -1, +1};
    
    int m = maps.size();
    int n = maps[0].size();

    vector<int> answer;
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(maps[i][j] != 'X' && !visited[i][j])
            {
                int foods = 0;
                queue<tuple<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                
                while(!q.empty())
                {
                    auto [y, x] = q.front(); q.pop();
                    foods += (maps[y][x]) - '0';
                    
                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        
                        if(ny >= 0 && ny < m && nx >= 0 && nx < n && maps[ny][nx] != 'X' && !visited[ny][nx])
                        {
                            q.push({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }
                }
                answer.push_back(foods);
            }
        }
    }
    
    // 12:55
    sort(answer.begin(), answer.end());
    return answer.empty() ? vector<int>{-1} : answer;
}