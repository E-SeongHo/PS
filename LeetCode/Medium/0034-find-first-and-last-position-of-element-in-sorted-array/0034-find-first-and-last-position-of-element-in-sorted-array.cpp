class Solution {
public:
    int LowerBound(vector<int>& nums, int begin, int end, int target)
    {
        if(begin >= end) 
        {
            if(begin >= 0 && nums[begin] == target) return begin;
            else return -1;
        }   
        int med = (begin + end) / 2;

        if(nums[med] < target) return LowerBound(nums, med+1, end, target);
        else return LowerBound(nums, begin, med, target);
    }
    int UpperBound(vector<int>& nums, int begin, int end, int target)
    {
        if(begin > end)
        {
            if(end >= 0 && nums[end] == target) return end;
            else return -1;
        }
        int med = (begin + end) / 2;

        if(nums[med] > target) return UpperBound(nums, begin, med-1, target);
        else return UpperBound(nums, med+1, end, target);
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        // vector<int> ret;
        
        // if(nums.empty()) return vector<int>(2, -1);

        // ret.push_back(LowerBound(nums, 0, nums.size()-1, target));
        // ret.push_back(UpperBound(nums, 0, nums.size()-1, target));

        // Solution2) Using STL algorithm
        vector<int> ret(2, -1);
        
        if(nums.empty()) return ret;

        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        cout << first << " " << last << endl;

        if(first == last) return ret;
        
        ret[0] = first;
        ret[1] = last-1;

        return ret;
    }
};