class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int begin = 0;
        int end = nums.size()-1;

        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) return mid;

            // check if it is in left part?
            if(nums[mid] >= nums[begin])
            {   
                if(target > nums[mid]) begin = mid+1;
                else
                {
                    if(target < nums[begin]) begin = mid+1;
                    else end = mid-1;
                }
            }
            else
            {
                if(target < nums[mid]) end = mid-1;
                else
                {
                    if(target > nums[end]) end = mid-1;
                    else begin = mid+1;
                }
            }
        }

        return -1;
    }
};