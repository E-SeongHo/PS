class Solution {
public:
    
    // O(N)
    int stringstreamParsing(string s)
    {
        stringstream sstream(s);
        string buffer;
        char deliminitor = ' ';
        
        int length = 0;
        while(getline(sstream, buffer, deliminitor))
        {
            if(buffer.size()) length = buffer.size();
        }
        
        return length;
    }
    
    // O(1)
    int naiveWay(string s)
    {
        int length = 0;
        bool counting = false;
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] != ' ' && !counting)
            {
                counting = true;
            }
            
            if(s[i] != ' ' && counting)
            {
                length++;
            }
            
            if(s[i] == ' ' && counting) break;
        }
        
        return length;
    }
    
    int lengthOfLastWord(string s) {
       return naiveWay(s);
    }
};