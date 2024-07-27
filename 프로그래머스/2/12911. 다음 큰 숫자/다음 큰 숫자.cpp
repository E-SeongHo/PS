#include <string>
#include <vector>

using namespace std;


int ones(int n)
{
    int cnt = 0;
    while(n)
    {
        if(n % 2 == 1) cnt++;        
        n = n / 2;
    }
    
    return cnt;
}

int solution(int n) 
{
    // 11:11
    
    int goal = ones(n);
    while(true)
    {
        int next = ones(++n);
        if(next == goal) return n;
    }
    // 11:24
    return 0;
}