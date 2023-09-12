class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        const int INF = -2147483648;
        vector<int> v(3, INF);
        int cnt = 0;
        bool infPassed = false;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == v[0] || nums[i] == v[1] || nums[i] == v[2])
            {
                if(nums[i] == INF && !infPassed) infPassed = true;
                else continue;
            }
            cnt++;
            if(nums[i] > v[0])
            {
                v[2] = v[1];
                v[1] = v[0];
                v[0] = nums[i];
            }else if(nums[i] > v[1])
            {
                v[2] = v[1];
                v[1] = nums[i];
            }else if(nums[i] > v[2])
            {
                v[2] = nums[i];
            }
        }
        
        if(cnt < 3)
        {
            return *max_element(nums.begin(), nums.end());
        }
        
        return v[2];
    }
};