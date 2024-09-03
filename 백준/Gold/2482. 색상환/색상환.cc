#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    vector<vector<int>> dp(N+1, vector<int>(K+1));

    for(int i = 1; i < N+1; ++i)
        dp[i][1] = i;

    for(int i = 4; i < N+1; ++i)
    {
        for(int j = 2; j < K+1; ++j)
        {
            if( j > i/2 ) break;
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % 1000000003;
        }
    }

    cout << dp[N][K];

    return 0;
}