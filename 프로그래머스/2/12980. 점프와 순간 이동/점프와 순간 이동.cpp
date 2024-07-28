#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    // 11:56
    
    int cnt = 0;
    while(n > 0)
    {
        if(n%2 == 1) 
        {
            n = (n-1)/2;
            cnt++;
        }
        else n = n/2;
    }

    // 12:07
    return cnt;
}