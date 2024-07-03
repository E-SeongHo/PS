#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

bool is_prime(long long n)
{
    if(n == 1) return false;
    if(n == 2) return true;
    
    for(long long i = 2; i * i <= n; i++)
    {
        if( n % i == 0 ) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    
    string knary;
    while(n)        
    {
        knary.push_back((n % k) + '0');
        n = n / k;
    }
    
    reverse(knary.begin(), knary.end());
    
    int answer = 0;
    string temp;
    for(int i = 0; i < knary.size(); i++)
    {
        if(knary[i] == '0')
        {
            if(!temp.empty() && is_prime(stol(temp))) answer++;
            temp.clear();
        }
        else
        {
            temp += knary[i];
        }
    }

    if(!temp.empty() && is_prime(stol(temp))) answer++;
               
    return answer;
}