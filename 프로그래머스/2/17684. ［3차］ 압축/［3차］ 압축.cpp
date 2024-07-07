#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    
    unordered_map<string, int> m;
    for(char c = 'A'; c <= 'Z'; c++)
    {
        string s;
        s += c;
        m[s] = c - 'A' + 1;
    }
    
    vector<int> answer;
    
    while(msg.size())
    {
        string temp;
        for(int i = msg.size(); i >= 0; i--)
        {
            temp = msg.substr(0, i);
            if(m.find(temp) != m.end())
            {
                answer.push_back(m[temp]);
                msg = msg.substr(i);
                if(msg.size()) m[temp + msg[0]] = m.size()+1;
                break;
            }
        }
    }
    
    return answer;
}