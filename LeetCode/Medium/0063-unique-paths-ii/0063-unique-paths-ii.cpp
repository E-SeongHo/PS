class Solution {
public:
    vector<vector<int>> map;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        map.resize(m+1, vector<int>(n+1));
        map[1][1] = !obstacleGrid[0][0];
        for(int i = 1; i < m+1; ++i)
        {
            for(int j = 1; j < n+1; ++j)
            {
                if(i == 1 && j == 1) continue;
                if(!obstacleGrid[i-1][j-1]) 
                    map[i][j] = map[i-1][j] + map[i][j-1];
            }
        }

        return map[m][n];
    }
};