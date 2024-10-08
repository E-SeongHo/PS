#include <iostream>
#include <vector>

using namespace std;

int T, N, M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;
        vector<int> coins(N+1);

        for(int i = 1; i <= N; ++i)
            cin >> coins[i];

        cin >> M;

        vector<vector<int>> dp(N+1, vector<int>(M+1));

        for(int i = 1; i <= N; ++i) 
        {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= M; ++j)
            {
                if(coins[i] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
                }
            }
        }

        cout << dp[N][M] << '\n';
    }
    return 0;
}