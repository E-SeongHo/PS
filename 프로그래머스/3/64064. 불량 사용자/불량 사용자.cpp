#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<set<string>> ret;

bool available(string& vanila, string& banned)
{
    if(vanila.size() != banned.size()) return false;
    
    for(int i = 0; i < banned.size(); i++)
    {
        if(banned[i] == '*') continue;
        
        if(vanila[i] != banned[i]) return false;
    }
    
    return true;
}

// bool contain(set<string>& candidate)
// {
//     for(auto s : ret)
//     {
//         if(s.size() != candidate.size()) continue;
        
//         bool same = true;
//         for(auto id : s)
//         {
//             if(candidate.find(id) == candidate.end()) 
//             {
//                 same = false;
//                 break;
//             }
//         }
//         if(same) return true;
//     }
    
//     return false;
// }
void dfs(vector<vector<string>>& availables, vector<string>& v, int depth)
{
    if(depth == availables.size())
    {
        set<string> s;
        for(auto id : v) s.insert(id);
        
        if(s.size() == availables.size()) ret.insert(s);

        return;
    }
    
    for(auto str : availables[depth])
    {
        v.push_back(str);
        dfs(availables, v, depth+1);
        v.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    vector<vector<string>> availables(banned_id.size());
    
    for(int i = 0; i < banned_id.size(); i++)
    {
        for(auto vanila : user_id)
        {
            if(available(vanila, banned_id[i])) 
                availables[i].push_back(vanila);
        }
    }
    
    vector<string> candidates;
    dfs(availables, candidates, 0);
    
    return ret.size();
}