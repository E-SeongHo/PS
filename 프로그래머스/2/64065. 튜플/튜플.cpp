#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    
    stringstream sstream(s);
    string buffer;
    
    vector<vector<int>> v(501);
    while(getline(sstream, buffer, '}'))
    {
        if(buffer.empty()) break;
        
        int idx = 0;
        while(!isdigit(buffer[idx++])) {}
        
        stringstream sub_stream(buffer.substr(idx-1));
        string sub_buffer;
        
        vector<int> nums;
        while(getline(sub_stream, sub_buffer, ','))
        {
            nums.push_back(stoi(sub_buffer));
        }
        
        v[nums.size()] = nums;
    }

    vector<int> answer;
    
    for(int i = 1; i < 501; i++)
    {
        if(!v[i].size()) break;
        
        for(int j = 0; j < i; j++)
        {
            if(find(answer.begin(), answer.end(), v[i][j]) == answer.end())
            {
                answer.push_back(v[i][j]);
                break;
            }
        }
    }
    
    return answer;
}