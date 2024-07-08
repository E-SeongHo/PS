#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    
    long long answer = 0;
    
    while(deliveries.size() || pickups.size())
    {
        for(auto it = deliveries.rbegin(); it != deliveries.rend(); ++it)
        {
            if(*it == 0) deliveries.pop_back();
            else break;
        }
        
        for(auto it = pickups.rbegin(); it != pickups.rend(); ++it)
        {
            if(*it == 0) pickups.pop_back();
            else break;
        }
        int weight = max(pickups.size(), deliveries.size()) * 2;
        
        int deliver = 0;
        for(int i = deliveries.size()-1; i >= 0; i--)
        {
            if(deliver + deliveries[i] < cap) 
            {
                deliver += deliveries[i];
                deliveries[i] = 0;
            }
            else 
            {
                deliveries[i] -= cap - deliver;
                deliver = cap;
                break;
            }
        }

        int pickup = 0;
        for(int i = pickups.size()-1; i >= 0; i--)
        {
            if(pickup + pickups[i] < cap)
            {
                pickup += pickups[i];
                pickups[i] = 0;
            }
            else
            {
                pickups[i] -= cap - pickup;
                pickup = cap;
                break;
            }
        }
        
        answer += weight;
    }
    
    return answer;
}