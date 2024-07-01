#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, pair<vector<int>, vector<int>>> in_and_out; 
unordered_map<int, int> visited;

void traverse(int current)
{
    visited[current] = true;
    
    for(auto vertex : in_and_out[current].second)
    {
        if(!visited[vertex]) traverse(vertex);
    }
}

vector<int> solution(vector<vector<int>> edges) {
    
    for(auto e : edges)
    {
        in_and_out[e[0]].second.push_back(e[1]);
        in_and_out[e[1]].first.push_back(e[0]);
    }
    
    int connecting_vertex = 0;
    for(auto vertex : in_and_out)
    {
        if(!vertex.second.first.size() && vertex.second.second.size() >= 2)
            connecting_vertex = vertex.first;
    }
    
    vector<int> answer;
    answer.resize(4);
    answer[0] = connecting_vertex;
    
    for(auto vertex : in_and_out)
    {
        visited.insert({vertex.first, false});
    }
    
    for(auto vertex : in_and_out)
    {
        if(vertex.first == connecting_vertex) continue;
        auto& in = vertex.second.first;
        auto& out = vertex.second.second;
        if(in.size() == 0 || in.size() == 1 && in[0] == connecting_vertex)
        {
            answer[2]++;
            traverse(vertex.first);
        }
        else if(out.size() == 2)
        {
            answer[3]++;
            traverse(vertex.first);
        }
    }
    
    for(auto v : visited)
    {
        if(v.first == connecting_vertex) continue;
        if(v.second == false)
        {
            answer[1]++;
            traverse(v.first);
        }
    }
    return answer;
}