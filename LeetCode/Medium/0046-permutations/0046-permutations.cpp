class Solution {
public:
    vector<vector<int>> ret;
    void pick(vector<int>& arr, vector<int>& picked)
    {
        if(picked.size() == arr.size())
        {
            ret.push_back(picked);
            return;
        }

        for(auto n : arr)
        {   // find O(1) since the constraints 1 <= nums.length <= 6
            if(find(picked.begin(), picked.end(), n) == picked.end())
            {
                picked.push_back(n);
                pick(arr, picked);
                picked.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> picked;
        pick(nums, picked);

        return ret;
    }
};