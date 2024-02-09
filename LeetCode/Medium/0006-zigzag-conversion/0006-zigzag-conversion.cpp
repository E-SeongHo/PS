class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        
        vector<string> v(numRows+1);
        
        int idx = 1;
        bool increasing = true;
        for(int i = 0; i < s.length(); i++)
        {
            v[idx] = v[idx] + s[i];
            if(increasing)
            {
                idx++;
                if(idx == numRows) increasing = false;
            }
            else
            {
                idx--;
                if(idx == 1) increasing = true;
            }
        }

        string ret;
        for(int i = 1; i <= numRows; i++)
        {
            ret = ret + v[i];
        }

        return ret;
    }
};