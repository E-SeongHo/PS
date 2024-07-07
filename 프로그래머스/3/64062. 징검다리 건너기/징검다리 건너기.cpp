#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) {

    multiset<int> kset;
    for(int i = 0; i < k; i++)
    {
        kset.insert(stones[i]);
    }
    
    int ret = *(--kset.end());
    for(int i = 1; i <= stones.size()-k; i++)
    {
        kset.erase(kset.find(stones[i-1]));
        kset.insert(stones[i+k-1]);
    
        ret = min(ret, *(--kset.end()));
    }
    
    return ret;
}