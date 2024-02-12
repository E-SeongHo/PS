class Solution {
public:
    void replace(vector<vector<int>>& matrix, int y, int x)
    {
        int ny = y; int nx = x;
        int temp = matrix[ny][nx];
        while(true)
        {
            swap(ny, nx);
            nx = matrix.size()-1 - nx;
            if(ny == y && nx == x) 
            {
                matrix[ny][nx] = temp;
                break;
            }                
            int temp2 = matrix[ny][nx];
            matrix[ny][nx] = temp;
            temp = temp2;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for(int i = 0; i < n/2; i++)
            for(int j = i; j < n-i-1; j++)
                replace(matrix, i, j);
    }
};