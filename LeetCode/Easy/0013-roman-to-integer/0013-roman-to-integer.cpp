class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> romanTable = 
            {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int sum = 0;
        int prev = 0;
        for(int i = s.size()-1; i >= 0; i--)
        {
            int converted = romanTable[s[i]];
            if(converted >= prev) sum += converted;
            else sum -= converted;

            prev = converted;
        }

        return sum;
    }
};