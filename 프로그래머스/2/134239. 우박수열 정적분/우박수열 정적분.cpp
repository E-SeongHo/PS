#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    // 2:18
    
    vector<double> areas;
    areas.reserve(10000);
    areas.push_back(0.0);
    
    int prev = k;
    while(k > 1)
    {
        if(k % 2 == 0) k /= 2;
        else k = k*3 + 1;
        
        double area = min(k, prev) + abs(k-prev) / 2.0;
        areas.push_back(area + areas.back());
        prev = k;
    }

    vector<double> answer;
    answer.reserve(ranges.size());

    for(auto& range : ranges)
    {
        int begin = range[0];
        int end = range[1];
        
        if(begin == 0 && end == 0) answer.push_back(areas.back());
        else 
        {
            end = int(areas.size()-1) + end;
            if(end < begin) answer.push_back(-1.0);
            else answer.push_back(areas[end] - areas[begin]);
        }
    }
    
    // 2:48
    return answer;
}