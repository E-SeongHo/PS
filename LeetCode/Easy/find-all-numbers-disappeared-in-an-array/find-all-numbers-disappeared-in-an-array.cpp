class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        // from discussion
        vector<int> v;
        
        for(int i = 0; i < nums.size(); ++i)
        {   
            int idx = abs(nums[i]) - 1;
            nums[idx] > 0 ? nums[idx] = -nums[idx] : nums[idx] = nums[idx]; 
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0) v.push_back(i + 1);
        }
        return v;
        
    }
};