#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;

int Combination(int n, int r)
{
    if(n==r || r == 0) return 1;
    else return Combination(n-1, r-1) + Combination(n-1, r);
}
int main()
{
    cin >> N;
    dp.resize(N+1);
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i < N+1; ++i)
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;

    cout << dp[N];

    return 0;
}