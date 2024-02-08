class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int mid = (nums.size()-1) / 2;
        int left = 0; int right = nums.size()-1;

        while(true)
        {
            bool dl = mid == 0 ? true : nums[mid] > nums[mid-1];
            bool dr = mid == nums.size()-1 ? true : nums[mid] > nums[mid+1];

            if(dl && dr) return mid;

            if(!dr)  // nums[mid] < nums[mid+1]
            {
                left = mid+1;
                mid = (mid+1 + right) / 2;
                continue;
            }
            if(!dl)  // nums[mid] < nums[mid-1]
            {
                right = mid-1;
                mid = (left + mid-1) / 2;
                continue;
            }
            cout << "exception occured" << endl;
        }
    }
};