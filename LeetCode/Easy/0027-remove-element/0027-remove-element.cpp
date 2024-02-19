class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int cnt = 0;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            if(nums[i] == val) 
            {
                swap(nums[i], nums[nums.size() - cnt - 1]);
                cnt++;
            }
            
        }
        
        return nums.size() - cnt;
    }
};