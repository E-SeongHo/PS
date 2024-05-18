class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int> copy = nums;
        for(int i = 0; i < nums.size(); i++)
        {
            int target = (i + k) % nums.size();
            
            nums[target] = copy[i];
        }
    }
};