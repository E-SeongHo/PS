class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // Solution2
        int ptr = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != val)
            {
                nums[ptr]=nums[i];
                ptr++;
            }
        }
        
        return ptr;
    }
};