class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int i = 1; i < triangle.size(); i++)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                auto& current = triangle[i][j];
                int l = max(0, j-1);
                int r = min((int)triangle[i-1].size()-1, j);
                
                current = min(current + triangle[i-1][l], current + triangle[i-1][r]);
            }
        }
        
        auto& lastLine = triangle[triangle.size()-1];
        int minE = *min_element(lastLine.begin(), lastLine.end());
        
        return minE;
    }
};