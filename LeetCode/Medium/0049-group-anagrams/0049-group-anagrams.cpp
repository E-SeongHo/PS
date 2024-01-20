class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> ret;

        for(auto str : strs)
        {
            string sorted = str;
            sort(sorted.begin(), sorted.end());

            if(m.find(sorted) == m.end())
            {
                vector<string> vs;
                vs.push_back(str);
                ret.push_back(vs);
                m[sorted] = ret.size()-1;
            }
            else
            {
                ret[m[sorted]].push_back(str);
            }
        }


        return ret;
    }
};