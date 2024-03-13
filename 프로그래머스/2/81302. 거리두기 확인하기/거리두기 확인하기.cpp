#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

bool find(vector<string>& place, vector<pair<int, int>>& people)
{
    for(auto person : people)
    {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(place.size(), vector<bool>(place[0].size()));
        
        q.push({person.first, person.second});
        visited[person.first][person.second] = true;
        
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int y = p.first;
            int x = p.second;
            
            for(int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                int dist = abs(person.first - ny) + abs(person.second - nx);
                if(dist > 2) continue;
                
                if(ny >= 0 && ny < place.size() && nx >= 0 && nx < place[0].size() && !visited[ny][nx])
                {
                    if(place[ny][nx] == 'P') return true;
                    
                    if(place[ny][nx] == 'O') 
                    {
                        q.push({ny ,nx});
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
    
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto place : places)
    {
        vector<pair<int, int>> people;
        for(int i = 0; i < place.size(); i++)
        {
            for(int j = 0; j < place[0].size(); j++)
            {
                if(place[i][j] == 'P') people.push_back({i, j}); 
            }
        }
        
        bool found = find(place, people);
        
        found ? answer.push_back(0) : answer.push_back(1);
    }
    
    return answer;
}