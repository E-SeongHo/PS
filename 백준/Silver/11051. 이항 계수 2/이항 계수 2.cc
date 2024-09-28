#include <iostream>
#include <vector>

using namespace std;

int N, K;
int main()
{
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

    cin >> N >> K;
    vector<vector<int>> dp(N+1, vector<int>(N+1, 1));

    for(int i = 2; i <= N; ++i)
    {
        for(int j = 1; j <= i-1; ++j)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[N][K];

    return 0;
}