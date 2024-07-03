#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    
    stringstream sstream(s);
    string buffer;
    
    string answer = "";
    int gap = 'a' - 'A';
    while(getline(sstream, buffer, ' '))
    {
        if(!isdigit(buffer[0]))
        {
            buffer[0] = buffer[0] >= 'a' ? buffer[0] - gap : buffer[0];
        }
        
        for(int i = 1; i < buffer.size(); i++)
        {
            buffer[i] = buffer[i] >= 'a' ? buffer[i] : buffer[i] + gap;
        }
        
        answer += buffer;
        answer += " ";
    }
    
    if(s.back() != ' ') answer.pop_back();
    
    return answer;
}