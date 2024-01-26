class Solution {
public:
    vector<string> phoneNumber = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> rets;

    void pick(string& ret, string& digits)
    {
        if(ret.size() == digits.size()) 
        {
            if(!ret.empty()) rets.push_back(ret);
            return;
        }
        
        int dial = digits[ret.size()] - '0';
        for(int i = 0; i < phoneNumber[dial].size(); i++)
        {
            ret.push_back(phoneNumber[dial][i]);
            pick(ret, digits);
            ret.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        string ret;
        pick(ret, digits);

        return rets;
    }
};