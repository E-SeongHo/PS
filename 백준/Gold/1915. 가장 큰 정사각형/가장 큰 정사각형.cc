#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<string> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];

    vector<vector<int>> dp(N, vector<int>(M));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            dp[i][j] = V[i][j] == '0' ? 0 : 1;

    int l = min(N, M);
    for(int i = 2; i <= l; ++i)
    {
        for(int y = i-1; y < N; ++y)
        {
            for(int x = i-1; x < M; ++x)
            {
                const int prev = (i-1) * (i-1);
                if(dp[y][x] >= prev && dp[y-1][x] >= prev && dp[y][x-1] >= prev && dp[y-1][x-1] >= prev)
                {
                   dp[y][x] = i*i;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}