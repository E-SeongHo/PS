class Solution {
public:
    string longestPalindrome(string s) {
        
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        
        for(int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
            if(i > 0) dp[i][i-1] = true;
        }

        string ret = "";
        ret.push_back(s[0]);

        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i+1; j < s.size(); j++)
            {
                if(dp[i+1][j-1] && s[j] == s[i])
                {   
                    dp[i][j] = true;
                    if(j - i + 1 > ret.size()) ret = s.substr(i, j-i+1);
                }
            }
        }
        
        return ret;
    }
};