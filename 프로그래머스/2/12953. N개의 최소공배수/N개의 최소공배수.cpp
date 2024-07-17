#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int solution(vector<int> arr) {
    
    // 1:56
    vector<int> primes;
    for(int n = 2; n <= 100; n++)
    {
        bool flag = false;
        for(int i = 2; i*i < n; i++)
        {
            if(n % i == 0)
            {
                flag = true;
                break;
            }
        }
        if(!flag) primes.push_back(n);
    }
    
    map<int, int> m;
    for(int i = 0; i < arr.size(); i++)
    {
        map<int, int> temp;
        int n = arr[i];
        while(n > 1)
        {
            for(auto prime : primes)
            {
                if(n % prime == 0)
                {
                    n /= prime;
                    temp[prime]++;
                    break;
                }
            }
        }
        for(auto p : temp)
        {
            m[p.first] = max(m[p.first], p.second);
        }
    }
    
    int ans = 1;
    for(auto p : m)
    {
        ans *= pow(p.first, p.second);
    }
    // 3:04 ;;
    return ans;
}