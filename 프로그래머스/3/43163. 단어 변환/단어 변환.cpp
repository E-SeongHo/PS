#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Target;
vector<string> Words;
vector<bool> Visited;
int ans = 9999;

void dfs(string current, int depth)
{
    if(current == Target)
    {
        ans = min(ans, depth);
        return;
    }
    
    for(int i = 0; i < Words.size(); i++)
    {
        if(!Visited[i])
        {
            int cnt = 0;
            for(int j = 0; j < Words[i].size(); j++)
            {
                if(current[j] != Words[i][j]) cnt++;
            }
            if(cnt == 1)
            {
                Visited[i] = true;
                dfs(Words[i], depth+1);
                Visited[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    // 3:26
    
    Words = words;
    Target = target;
    Visited.resize(words.size(), false);
    
    dfs(begin, 0);
    
    // 3:43
    return ans == 9999 ? 0 : ans;
}