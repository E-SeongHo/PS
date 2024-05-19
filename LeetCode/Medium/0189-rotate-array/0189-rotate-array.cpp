class Solution {
public:
    
    void naive_copy(vector<int>& nums, int k)
    {
        vector<int> copy = nums;
        for(int i = 0; i < nums.size(); i++)
        {
            int target = (i + k) % nums.size();
            
            nums[target] = copy[i];
        }
    }
    
    void inplace_circular(vector<int>& nums, int k)
    {
        int cnt = nums.size();
        int start = 0;
        while(cnt)
        {
            int current = start;
            int value = nums[current];
            while(true)
            {
                int target = (current + k) % nums.size();
                int temp = nums[target];
                nums[target] = value;
                value = temp;
                current = target;
                cnt--;

                if(current == start) break;
            }
            start++;
        }
    }
    
    void inplace_flip(vector<int>& nums, int k)
    {
        for(int i = 0; i < nums.size()/2; i++)
        {
            swap(nums[i], nums[nums.size()-1 - i]);
        }
        
        for(int i = 0; i < k/2; i++)
        {
            swap(nums[i], nums[k-1-i]);
        }
        
        for(int i = k; i < (nums.size()+k)/2; i++)
        {
            swap(nums[i], nums[nums.size()-1 - (i-k)]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        
        k = k%nums.size();
        inplace_flip(nums, k);
    }
};