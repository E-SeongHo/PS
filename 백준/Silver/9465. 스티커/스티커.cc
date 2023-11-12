#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    for(int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;
        vector<vector<int>> v(2, vector<int>(N));
        vector<vector<int>> dp(2, vector<int>(N+2));
        
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < N; ++j)
                cin >> v[i][j];

        dp[0][1] = v[0][0];
        dp[1][1] = v[1][0];

        for(int i = 2; i < N+1; ++i)
        {
            int idx = i-1;
            dp[0][i] = max(max(dp[0][i-2] + v[0][idx], dp[1][i-1] + v[0][idx]), dp[0][i-1]);
            dp[1][i] = max(max(dp[1][i-2] + v[1][idx], dp[0][i-1] + v[1][idx]), dp[1][i-1]);
        }

        cout << max(dp[0][N], dp[1][N]) << "\n";
    }

    return 0;
}