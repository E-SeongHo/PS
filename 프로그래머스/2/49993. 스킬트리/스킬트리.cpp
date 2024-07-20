#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    // 5:10
    vector<int> order(26, 0);

    int i = 0;
    for(char s : skill) 
        order[s-'A'] = ++i;
    
    int answer = 0;
    for(string& st : skill_trees)
    {
        int i = 0;
        bool flag = false;
        for(char s : st)
        {
            if(!order[s-'A']) continue;
            if(order[s-'A'] != ++i) 
            {
                flag = true;
                break;
            }
        }
        if(!flag) answer++;
    }
    
    // 5:20
    return answer;
}