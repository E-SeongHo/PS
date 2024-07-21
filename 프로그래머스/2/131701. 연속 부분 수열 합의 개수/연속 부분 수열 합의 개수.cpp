#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<int> sums;

int solve(vector<int> elements)
{
    int n = elements.size();
    
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < i+n; j++)
        {
            sum += elements[j%n];
            sums.insert(sum);
        }
    }
    
    return sums.size();
}

int solution(vector<int> elements) 
{
    // !
    return solve(elements);
    
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
    // 3:00
    return sums.size();
}