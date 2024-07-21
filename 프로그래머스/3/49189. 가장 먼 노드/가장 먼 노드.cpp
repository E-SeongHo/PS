#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    // 3:32
    
    vector<vector<int>> g(n+1);
    for(auto& p : edge)
    {
        g[p[0]].push_back(p[1]);
        g[p[1]].push_back(p[0]);
    }
    
    queue<pair<int, int>> q;
    vector<bool> visited(n+1, false);
    
    q.push({1, 0});
    visited[1] = true;
    int max_depth = 0;
    int cnt = 0;
    
    while(!q.empty())
    {
        auto [current, depth] = q.front(); q.pop();
        
        if(depth == max_depth) cnt++;
        if(depth > max_depth) 
        {
            max_depth = depth;
            cnt = 1;
        }
        
        for(auto vertex : g[current])
        {
            if(!visited[vertex])
            {
                q.push({vertex, depth+1});
                visited[vertex] = true;
            }
        }
    }
    // 3:41
    return cnt;
}