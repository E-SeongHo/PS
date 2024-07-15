#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    vector<int> cnt(11, 0);
    queue<pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        q.push({i, priorities[i]});
        cnt[priorities[i]]++;
    }
    
    int poped = 0;
    while(true)
    {
        auto [pos, priority] = q.front(); q.pop();
        
        bool flag = false;
        for(int i = priority+1; i < cnt.size(); i++)
        {
            if(cnt[i]) 
            {
                flag = true;
                break;
            }
        }
        
        if(flag) 
        {
            q.push({pos, priority});
        }
        else
        {
            if(pos == location) break;
            
            cnt[priority]--;
            poped++;
        }
    }

    return poped+1;
}