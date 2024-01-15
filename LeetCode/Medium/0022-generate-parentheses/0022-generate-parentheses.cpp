class Solution {
public:
    bool isOpened(const string& s)
    {
        int opened = 0;
        for(auto c : s)
        {
            if(c == '(') opened++;
            else opened--;
        }
        return opened;
    }
    bool isValid(const string& s)
    {
        return !isOpened(s);
    }
    void func(vector<string>& out, string s, const int n)
    {
        if(s.length() == 2*n)
        {
            if(isValid(s)) out.push_back(s);
            return;
        }
        func(out, s+"(", n);
        if(isOpened(s)) func(out, s+")", n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string start = "(";

        func(out, start, n);    

        return out;
    }
};