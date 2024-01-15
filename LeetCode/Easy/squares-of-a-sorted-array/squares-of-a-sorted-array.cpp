class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> sorted(nums.size(), 0); // size with all value 0
        int lp = 0;
        int rp = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            if(abs(nums[lp]) > abs(nums[rp]))
            {
                sorted[i] = abs(nums[lp]);
                lp++;
            }
            else
            {
                sorted[i] = abs(nums[rp]);
                rp--;
            }
        }
        
        for(auto& n : sorted)
        {
            n = n*n;
        }
        return sorted;
    }
};