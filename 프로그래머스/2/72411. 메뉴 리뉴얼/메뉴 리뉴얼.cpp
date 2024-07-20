
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

void dfs(string& src, int next, int r, string& s, unordered_map<string, int>& m)
{
    if(s.size() == r)
    {
        m[s]++;
        return;
    }
    
    for(int i = next; i < src.size(); i++)
    {
        s.push_back(src[i]);
        dfs(src, i+1, r, s, m);
        s.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
    // 4:40
    vector<unordered_map<string, int>> m(course.size());
    
    for(int i = 0; i < course.size(); i++)
    {
        for(string& order : orders)
        {
            sort(order.begin(), order.end());
            string s;
            dfs(order, 0, course[i], s, m[i]); 
        }
    }
    
    vector<string> ans;
    for(auto& e : m)
    {
        int max_cnt = 1;
        for(auto& p : e) max_cnt = max(max_cnt, p.second);
            
        if(max_cnt < 2) continue; 
        for(auto& p : e) 
            if(p.second == max_cnt) ans.push_back(p.first);
    }
    
    sort(ans.begin(), ans.end());
    
    // 5:07
    return ans;
}