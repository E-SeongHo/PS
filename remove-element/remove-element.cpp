class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int front = 0;
        int back = nums.size() - 1;
        
        while(front <= back && back >= 0)
        {
            if(nums[back] == val)
            {
                cnt++;
                back--;
                continue;
            }
            if(nums[front] == val)
            {
                int temp = nums[front];
                nums[front] = nums[back];
                nums[back] = temp;
            }
            else front++;
        }
        
        
        return nums.size() - cnt;
    }
};