#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(string s) {
    
    int zeros = 0;
    int iterates = 0;
    
    string temp = s;
    while(temp != "1")
    {
        int cnt = 0;
        for(auto c : temp)
        {
            if(c == '0') cnt++;
        }
        
        int num = temp.size() - cnt;
        string transformed;
        while(num)
        {
            transformed = to_string(num % 2) + transformed;
            num = num / 2;
        }

        temp = transformed;
        zeros += cnt;
        iterates++;
    }
    
    vector<int> answer;
    answer.push_back(iterates);
    answer.push_back(zeros);
    
    return answer;
}