class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Solution1) O(NlogN), O(N)        
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() / 2];

        // Follow-up: Could you solve the problem in linear time and in O(1) space?
        // Moore Voting Algorithm

        int candidate = nums[0];
        int cnt = 0;

        for(int num : nums)
        {   
            if(cnt == 0) candidate = num;
            
            cnt += candidate == num ? 1 : -1;
        }

        // verify candidate 
        cnt = 0;
        for(int num : nums)
            if(num == candidate) cnt++;

        if(cnt > nums.size()/2) return candidate;
        else return -1; // means no majority number exists in the input array
    }
};