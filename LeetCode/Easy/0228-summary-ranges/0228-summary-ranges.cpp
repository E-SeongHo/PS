class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.size() == 0) return ret;
        
        string temp = "";
       
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1] != nums[i]+1)
            {
                if(temp == "") 
                {
                    temp += to_string(nums[i]);
                }
                else
                {
                    temp += "->" + to_string(nums[i]);
                }
                ret.push_back(temp);
                temp = "";
            }
            else
            {
                if(temp == "")
                {
                    temp += to_string(nums[i]);
                }
            }
        }
        
        if(temp != "") temp += "->";
        temp += to_string(nums.back());
        ret.push_back(temp);
            
        return ret;
    }
};