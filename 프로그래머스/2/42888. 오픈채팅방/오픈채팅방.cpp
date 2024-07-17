#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    // 3:06
    
    vector<pair<string, string>> abstract;
    unordered_map<string, string> id_map;
    
    for(auto& r : record)
    {
        stringstream sstream(r);
        vector<string> buffer;
        string temp;
        while(getline(sstream, temp, ' '))
        {
            buffer.push_back(temp);
        }
        
        if(buffer.front() == "Enter")
        {
            abstract.push_back({buffer[0], buffer[1]});
            if(id_map.find(buffer[0]) == id_map.end())
            {
                id_map[buffer[1]] = buffer[2];
            }
        }
        else if(buffer.front() == "Leave")
        {
            abstract.push_back({buffer[0], buffer[1]});
        }
        else if(buffer.front() == "Change")
        {
            id_map[buffer[1]] = buffer[2];
        }
    }
    
    vector<string> answer;
    for(auto& r : abstract)
    {
        string s;
        if(r.first == "Enter")
        {
            s = id_map[r.second] + "님이 들어왔습니다.";
        }
        else
        {
            s = id_map[r.second] + "님이 나갔습니다.";
        }
        
        answer.push_back(s);
    }
    
    // 3:20
    return answer;
}