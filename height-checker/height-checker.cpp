class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        
        int cnt = 0;
        for(int i = 0; i < expected.size(); ++i)
        {
            if(expected[i] != heights[i]) cnt++;
        }
        
        return cnt;
    }
};