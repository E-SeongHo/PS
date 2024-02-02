class Solution {
public:
    struct Compare
    {
        bool static operator()(const string& s1, const string& s2)
        {
            return s1 + s2 > s2 + s1;
        }
    };
    string largestNumber(vector<int>& nums) {
        
        string ret;

        multiset<string, Compare> numSet;
        for(auto n : nums)
        {
            numSet.insert(to_string(n));
        }

        if(*numSet.begin() == "0") return "0";

        for(auto s : numSet)
            ret = ret + s;
            
        return ret;
    }
};