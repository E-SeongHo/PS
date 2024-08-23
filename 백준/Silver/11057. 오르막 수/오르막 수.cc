#include <iostream>
#include <vector>

using namespace std;

int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    vector<vector<long long>> dp(N+1, vector<long long>(10));

    for(int i = 0; i < 10; ++i)
        dp[1][i] = 1;

    for(int i = 2; i < N+1; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            for(int k = j; k < 10; ++k)
            {
                dp[i][k] += dp[i-1][j] % 10007;
            }
        }
    }

    long long ret = 0;
    for(int i = 0; i < 10; ++i)
    {
        ret += dp[N][i] % 10007;
    }

    cout << ret % 10007;

    return 0;
}