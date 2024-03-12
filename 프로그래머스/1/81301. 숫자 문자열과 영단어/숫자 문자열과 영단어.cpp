#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


unordered_map<string, int> table = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
                                    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

int solution(string s) {
    int answer = 0;
    
    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(temp != "")
        {
            if(table.find(temp) != table.end())
            {
                answer *= 10;
                answer += table[temp];   
                temp = "";
            }
        }
        if(s[i] >= '0' && s[i] <= '9') 
        {
            answer *= 10;
            answer += s[i] - '0';
        }
        else temp += s[i];
    }
        
    if(temp != "") 
    {
        answer *= 10;
        answer += table[temp];
    }
    
    return answer;
}