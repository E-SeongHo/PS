class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0) return false;

        string str = to_string(x);

        int lp = 0;
        int rp = str.size()-1;
        while(lp < rp)
        {
            if(str[lp++] != str[rp--]) return false;
        }
        
        return true;

    }
};