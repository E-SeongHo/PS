class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // In-Place Operation
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] % 2 == 0)
            {
                int temp = nums[cnt]; 
                nums[cnt] = nums[i];
                nums[i] = temp;
                cnt++;
            }
        }
        
        return nums;
    }
};