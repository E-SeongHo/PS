#include <iostream>
#include <vector>

using namespace std;

unsigned long long N;
int main()
{
    cin >> N;

    if(N == 0) 
    {
        cout << 0;
        return 0;
    }

    unsigned long long begin = 0;
    unsigned long long end = (unsigned long long)1<<32;

    while(begin + 1 < end)
    {
        unsigned long long mid = (begin + end) / 2;

        if((mid * mid) < N) begin = mid;
        else end = mid;
    }

    cout << end;
    return 0;
}