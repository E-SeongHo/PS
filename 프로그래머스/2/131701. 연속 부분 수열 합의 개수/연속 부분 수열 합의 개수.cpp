#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<int> sums;

int solution(vector<int> elements) 
{
    // 2:30
    int n = elements.size();
    for(int i = 0; i < n-1; i++)
        elements.push_back(elements[i]);
    
    for(int i = 1; i < elements.size(); i++)
        elements[i] += elements[i-1];     
    
    for(int r = 1; r <= n; r++)
    {
        sums.insert(elements[r-1]);
        for(int i = 1; i < n; i++)
            sums.insert(elements[i+r-1] - elements[i-1]);
    }
    
    return sums.size();
}