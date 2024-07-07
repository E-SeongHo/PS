#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int standard_time;
int standard_fee;
int unit_time;
int unit_fee;

int calc_time(const string& in, const string& out)
{
    int in_hour = stoi(in.substr(0, 2));
    int in_minute = stoi(in.substr(3, 2));
    
    int out_hour = stoi(out.substr(0, 2));
    int out_minute = stoi(out.substr(3, 2));
    
    int hour = out_hour - in_hour;
    int minute = out_minute - in_minute;
    
    if(minute < 0) 
    {
        minute = minute + 60;
        hour--;
    }
    int time = hour * 60 + minute;
    
    return time;
}
int calc_fee(int time)
{
    if(time > standard_time)
    {
        int over_time = time - standard_time;
        int over_cost = (over_time / unit_time) * unit_fee;
        if(over_time % unit_time != 0) over_cost += unit_fee;
        
        return over_cost + standard_fee;
    }
    else return standard_fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    standard_time = fees[0];
    standard_fee = fees[1];
    unit_time = fees[2];
    unit_fee = fees[3];
    
    unordered_map<int, string> in;
    unordered_map<int, int> sum;
    
    for(auto record : records)
    {
        stringstream sstream(record);
        string buffer;
        
        vector<string> parsed;
        while(getline(sstream, buffer, ' '))
        {
            parsed.push_back(buffer);
        }
        
        if(parsed.back() == "IN") 
        {
            in[stoi(parsed[1])] = parsed[0];
        }
        else 
        {   
            sum[stoi(parsed[1])] += calc_time(in[stoi(parsed[1])], parsed[0]);
            in.erase(stoi(parsed[1]));                                    
        }
    }
    
    if(in.size())
    {
        for(auto record : in)    
        {
            sum[record.first] += calc_time(record.second, "23:59");
        }
    }
    
    vector<pair<int, int>> v;
    for(auto record : sum)
    {
        int fee = calc_fee(record.second);
        v.push_back({record.first, fee});
    }
    
    sort(v.begin(), v.end());
    
    vector<int> answer;
    for(auto p : v)
    {
        answer.push_back(p.second);
    }
    
    return answer;
}