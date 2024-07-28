#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) 
{
    // 12:18
    vector<vector<int>> graph(info.size());

    for(auto edge : edges)
    {
        int n1 = edge[0];
        int n2 = edge[1];
        
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    // current, visited pair
    set<pair<int, int>> s;
    s.insert({0, 1<<0});
    
    // current, visited, sheeps, wolves
    queue<tuple<int, int, int, int>> q;
    q.push({0, 1<<0, 1, 0});
    
    int ret = 0;
    while(!q.empty())
    {
        auto [current, visited, sheeps, wolves] = q.front(); q.pop();
        ret = max(ret, sheeps);
        
        for(auto next : graph.at(current))
        {
            bool visited_next = visited & (1<<next);
            bool duplicated = s.find({next, visited | 1 << next}) != s.end(); 
            
            if(duplicated) continue;
            s.insert({next, visited | 1 << next});
            
            int new_sheeps = sheeps;
            int new_wolves = wolves;
            if(!visited_next && info.at(next) == 0) new_sheeps++;
            if(!visited_next && info.at(next) == 1) new_wolves++;
            
            if(new_sheeps > new_wolves)
            {
                q.push({next, (visited | (1<<next)), new_sheeps, new_wolves});        
            }
        }
    }
    
    // 1:04 return 생략하면 segfault!!!
    return ret;
}