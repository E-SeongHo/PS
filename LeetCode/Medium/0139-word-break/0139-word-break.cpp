class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> table(s.size()+1);
        table[0] = true;
        
        for(int i = 1; i < table.size(); i++)
        {
            bool flag = false;
            for(auto& word : wordDict)
            {
                int ptr = i - word.size();
                if(ptr >= 0 && table[ptr])
                {
                    if(s.substr(ptr, word.size()) == word)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            table[i] = flag;
        }
        
        return table.back();
    }
};