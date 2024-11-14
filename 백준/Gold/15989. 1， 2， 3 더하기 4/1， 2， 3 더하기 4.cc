#include <iostream>
#include <vector>

using namespace std;

int T, N;

int tabulation2D()
{
    vector<vector<int>> dp(4, vector<int>(N+1, 0));
    for(int i = 0; i <= 3; i++)
    {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(j-i >= 0)
            {
                // i-1까지 고려해서 만들 수 있는 j + i를 한번 더 사용해서 만들 수 있는 j
                dp[i][j] = dp[i-1][j] + dp[i][j-i];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[3][N];
}

int optimized_tabulation()
{
    vector<int> dp(N+1);
    dp[0] = 1;
    
    for(int i = 1; i <= 3; i++)
    {
        for(int j = i; j <= N; j++)
        {
            dp[j] += dp[j-i];
        }
    }

    return dp[N];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> N;
        //cout << tabulation2D() << '\n';
        cout << optimized_tabulation() << '\n';
    }

    return 0;
}
