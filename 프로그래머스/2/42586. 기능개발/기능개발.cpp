#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    // 3:12
    vector<int> answer;
    int n = progresses.size();
    int done = -1;
    while(done < n-1)
    {
        for(int i = done+1; i < progresses.size(); i++)
            progresses[i] += speeds[i];
        
        if(progresses[done+1] >= 100)
        {
            int cnt = 0;
            for(int i = done+1; i < progresses.size(); i++)
            {
                if(progresses[i] >= 100) cnt++;
                else break;
            }
            done += cnt;
            
            answer.push_back(cnt);
        }
    }
    
    // 3:25
    return answer;
}