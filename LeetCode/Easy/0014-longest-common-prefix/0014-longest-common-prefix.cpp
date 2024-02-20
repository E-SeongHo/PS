class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string lcp;
        if(strs.size() == 0) return lcp;

        int i = 0;
        while(1)
        {
            for(int j = 0; j < strs.size(); j++)
            {
                if(i < strs[j].size())
                {
                    if(i < lcp.size()) 
                    {
                        if(lcp[i] != strs[j][i])
                        {
                            lcp.pop_back();
                            return lcp;
                        }
                    }
                    else lcp.push_back(strs[j][i]);
                }
                else 
                {   
                    if(j != 0) lcp.pop_back();
                    return lcp;
                }
            }
            i++;
        }
    }
};