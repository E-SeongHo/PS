class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, string> hash;
        set<string> words;

        istringstream iss(s);
        string buffer;

        for(auto c : pattern)
        {
            if(!getline(iss, buffer, ' ')) return false;
            if(hash.find(c) != hash.end())
            {
                if(hash[c] != buffer) return false;
            }
            else
            {
                if(words.find(buffer) != words.end()) return false;
                else 
                {
                    words.insert(buffer);
                    hash[c] = buffer;
                }
            }
        }

        if(getline(iss, buffer, ' ')) return false;
        return true;
    }
};