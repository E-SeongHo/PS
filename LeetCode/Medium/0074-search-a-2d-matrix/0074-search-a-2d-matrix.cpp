class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int column = matrix[0].size();
        int n = row * column;

        int begin = 0;
        int end = n-1;

        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            int r = mid / column;
            int c = mid - r*column;
            
            if(target == matrix[r][c]) return true;
            else if(target > matrix[r][c]) begin = mid + 1;
            else end = mid - 1;
        }
        
        return false;
    }
};