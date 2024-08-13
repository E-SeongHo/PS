#include <iostream>
#include <vector>

using namespace std;

int T, W;
vector<int> Tree;

int main()
{
    cin >> T >> W;
    Tree.resize(T);

    for(int i = 0; i < T; ++i)
        cin >> Tree[i];

    vector<vector<vector<int>>> dp(T+1, vector<vector<int>>(W+1, vector<int>(3)));
    
    for(int i = 1; i < T+1; ++i)
    {
        if(Tree[i-1] == 1) dp[i][W][1] = dp[i-1][W][1] + 1;
        else dp[i][W][1] = dp[i-1][W][1];
    }

    for(int i = 1; i < T+1; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            if(j < W-i) continue;

            if(Tree[i-1] == 1)
            {
                dp[i][j][1] = max(max(dp[i][j][1], dp[i-1][j+1][2] + 1), dp[i-1][j][1] + 1);
                dp[i][j][2] = max(max(dp[i][j][2], dp[i-1][j][2]), dp[i-1][j+1][1]);
            }
            else
            {
                dp[i][j][1] = max(max(dp[i][j][1], dp[i-1][j+1][2]), dp[i-1][j][1]);
                dp[i][j][2] = max(max(dp[i][j][2], dp[i-1][j][2] + 1), dp[i-1][j+1][1] + 1);
            }
        }
    }

    int ret = 0;
    for(int i = 0; i <= W; ++i)
    {
        ret = max(ret, dp[T][i][1]);
        ret = max(ret, dp[T][i][2]);
    }

    cout << ret;
    return 0;
}