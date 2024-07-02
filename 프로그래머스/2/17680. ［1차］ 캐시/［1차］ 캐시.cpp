#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> Cache;
int Size;
int CurrentSize = 0;

bool caching(string s)
{
    auto it = find(Cache.begin(), Cache.end(), s);
    
    if(it != Cache.end()) // hit
    {
        int idx = it - Cache.begin();
        for(int i = idx; i >= 1; i--)
        {
            Cache[i] = Cache[i-1];    
        }
        
        Cache[0] = s;
    }
    else // miss
    {
        if(CurrentSize == Size)
        {
            for(int i = Size-1; i >= 1; i--)
            {
                Cache[i] = Cache[i-1];
            }
        }
        else
        {
            for(int i = CurrentSize; i >= 1; i--)
            {
                Cache[i] = Cache[i-1];
            }
            CurrentSize++;
        }
       
        Cache[0] = s;
    }
    
    return it != Cache.end();
}
int solution(int cacheSize, vector<string> cities) {
    
    Size = cacheSize;
    Cache.resize(Size);

    if(!Size) return cities.size() * 5;
    
    int answer = 0;
    for(auto city : cities)
    {
        for(auto& c : city)
        {
            if(c >= 'a') c = c - ('a' - 'A');
        }
        caching(city) ? answer+=1 : answer+=5;
    }

    return answer;
}