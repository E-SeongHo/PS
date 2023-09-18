class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> v;
        
        for(int i = 0; i < nums.size(); ++i)
        {   
            for(int j = 0; j < nums.size(); ++j)
            {                
                int temp = nums[i];
                if(nums[i] == nums[temp-1]) break;
                else
                {
                    nums[i] = nums[nums[i]-1];
                    nums[temp-1] = temp;
                }
            }
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1) v.push_back(i+1);
        }
        return v;
        
    }
};