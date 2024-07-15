#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    set<string> s;
    s.insert(words[0]);
    int turn = 1;
    
    vector<int> answer(2, 0);
    for(int i = 1; i < words.size(); i++)
    {
        if(words[i].front() != words[i-1].back() || s.find(words[i]) != s.end())
        {
            answer[0] = turn + 1;
            answer[1] = (i / n) + 1;
            break;
        }
        
        s.insert(words[i]);
        turn = (turn + 1) % n;
    }
    
    return answer;
}