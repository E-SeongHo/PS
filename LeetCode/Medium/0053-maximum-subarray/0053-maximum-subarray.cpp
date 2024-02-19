class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int ret = -987654321;

        for(auto n : nums)
        {
            sum += n;
            ret = max(sum, ret);    

            if(sum < 0) sum = 0;
        }

        return ret;
    }
};