#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int r = 1000000007;
unordered_map<long long, long long> map;

long long big_fibonacci(long long n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(n % 2 == 1)
    {
        if(map.find(n/2) == map.end()) map[n/2] = big_fibonacci(n/2);
        long long n1 = map[n/2];

        if(map.find(n/2 + 1) == map.end()) map[n/2 + 1] = big_fibonacci(n/2 + 1);
        long long n2 = map[n/2 + 1];

        long long ret = ((n1 * n1)%r + (n2 * n2)%r)%r;
        map[n] = ret;
        
        return ret;
    }
    else
    {
        if(map.find(n/2) == map.end()) map[n/2] = big_fibonacci(n/2);
        long long n1 = map[n/2];

        if(map.find(n/2 - 1) == map.end()) map[n/2 - 1] = big_fibonacci(n/2 - 1);
        long long n2 = map[n/2 - 1];

        long long ret = ((n1 * n1)%r + (n1 * 2 * n2)%r)%r;
        map[n] = ret;

        return ret;
    }
}

int main()
{
    long long n;
    cin >> n;

    cout << big_fibonacci(n);
}