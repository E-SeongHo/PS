#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<char> Foods;
vector<vector<bool>> Orders;

bool check(vector<bool>& order, string& s)
{
    for(char c : s)
    {
        if(!order[c-'A']) return false;
    }
    
    return true;
}

void dfs(int next, int r, string& s, vector<pair<int, string>>& candidates, int& max_cnt)
{
    if(s.size() == r)
    {
        int cnt = 0;
        for(int i = 0; i < Orders.size(); i++)
        {
            if(check(Orders[i], s)) cnt++;
        }
        max_cnt = max(max_cnt, cnt); 
        if(cnt >= 2) candidates.push_back({cnt, s});
        
        return;
    }
    
    for(int i = next; i < Foods.size(); i++)
    {
        s = s + Foods[i];
        dfs(i+1, r, s, candidates, max_cnt);
        s.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    Orders.resize(orders.size(), vector<bool>(26, false));
    
    vector<bool> foods(26, false);
    for(int i = 0; i < orders.size(); i++)
    {
        for(char c : orders[i])
        {
            foods[c-'A'] = true;
            Orders[i][c-'A'] = true;
        }
    }
    
    for(int i = 0; i < foods.size(); i++)
    {
        if(foods[i]) Foods.push_back(char(i+'A'));
    }
        
    vector<string> courses;
    for(int r : course)
    {
        string s;
        vector<pair<int, string>> candidates;
        int max_cnt = 0;
        dfs(0, r, s, candidates, max_cnt);
        
        if(max_cnt < 2) continue;
        
        for(auto p : candidates)
        {
            if(p.first == max_cnt) courses.push_back(p.second);
        }
        
    }
    
    sort(courses.begin(), courses.end());
    
    return courses;
}