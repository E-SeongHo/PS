class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        // in place : O(1) space complexity
        // everything comes with a price
        bool rowFlag = false;
        bool columnFlag = false;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if(i == 0) rowFlag = true;
                    if(j == 0) columnFlag = true;
                }
            }
        }

        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(rowFlag)
        {
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }

        if(columnFlag)
        {
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};