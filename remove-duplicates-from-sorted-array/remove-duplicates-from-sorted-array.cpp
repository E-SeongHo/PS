class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 0;
        int rpt = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!rpt)
            {
                nums[ptr++] = nums[i];
            }
            if(i == (nums.size()-1)) break;
            if(nums[i] == nums[i+1]) rpt++;
            else rpt = 0;
        }
        
        return ptr;
    }
};