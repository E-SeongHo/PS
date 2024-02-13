class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1, vector<int>(grid[0].size()+1));

        for(int i = 0; i < dp.size(); i++) dp[i][0] = 9999;
        for(int i = 0; i < dp[0].size(); i++) dp[0][i] = 9999;

        dp[1][1] = grid[0][0];
        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = 1; j < dp[0].size(); j++)
            {
                if(i == 1 && j == 1) continue;
                int value = grid[i-1][j-1];
                dp[i][j] = min(value + dp[i-1][j], value + dp[i][j-1]);
            }
        }

        return dp[dp.size()-1][dp[0].size()-1];
    }
};