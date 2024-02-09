class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // revised)  simpler tabulation (from the bottom)
        // Idea : paths are the same from top to bottom and from bottom to top
        for(int i = triangle.size()-2; i >= 0; i--)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                auto& current = triangle[i][j];
                auto& bottomLine = triangle[i+1];
                
                current += min(bottomLine[j], bottomLine[j+1]);
            }
        }
        
        return triangle[0][0];
    }
};