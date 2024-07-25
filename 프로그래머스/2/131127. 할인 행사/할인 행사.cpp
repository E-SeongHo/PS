#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    // 10:23

    unordered_map<string, int> available;
    for(string& item : want)
    {
        available.insert({item, 0});
    }
    
    for(int i = 0; i < 10; i++)
    {
        if(available.find(discount[i]) != available.end())
            available[discount[i]]++;
    }

    int answer = 0;
    for(int i = 0; i <= discount.size() - 10; i++)
    {
        bool flag = false;
        for(int j = 0; j < want.size(); j++)
        {
            if(available[want[j]] < number[j]) 
            {
                flag = true;
                break;
            }
        }
        if(!flag) answer++;
        
        if(i != discount.size() - 10)
        {
            if(available.find(discount[i]) != available.end())
                available[discount[i]]--;
            if(available.find(discount[i+10]) != available.end())
                available[discount[i+10]]++;
        }
    }
    
    // 10:56
    return answer;
}