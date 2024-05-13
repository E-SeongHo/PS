class Solution {
public:

    int rob_memoization(vector<int>& nums)
    {
        return rob_memoization(nums, nums.size()-1);
    }
    int rob_memoization(vector<int>& nums, int i)
    {
        if(i < 0) return 0;
        return max(nums[i] + rob_memoization(nums, i-2), rob_memoization(nums, i-1));
    }

    int rob_tabulation(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;

        vector<int> dp(nums.size()+1);

        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) 
        {
            dp[i+1] = max(dp[i-1] + nums[i], dp[i]);
        }

        return dp.back();
    }

    int rob(vector<int>& nums)
    {
        return rob_tabulation(nums);
    }
};