#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int iter = 0;
    while(++iter)
    {
        int n;
        cin >> n;
        if(n == 0) break;

        vector<vector<int>> g(n, vector<int>(3));

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 3; ++j)
                cin >> g[i][j];

        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = 1000;
        dp[0][1] = g[0][1];
        dp[0][2] = g[0][1] + g[0][2];

        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + g[i][0];
            dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]}) + g[i][1];
            dp[i][2] = min({dp[i-1][1], dp[i-1][2], dp[i][1]}) + g[i][2];
        }

        cout << iter << ". " << dp[n-1][1] << "\n";
    }

    return 0;
}