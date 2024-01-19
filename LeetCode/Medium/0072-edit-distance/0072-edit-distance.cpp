class Solution {
public:
    int minDistance(string word1, string word2) {
        
        if(word1.size() < word2.size()) swap(word1, word2);

        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        
        for(int i = 0; i < word1.size()+1; i++)
            dp[i][0] = i;
        for(int i = 0; i < word2.size()+1; i++)
            dp[0][i] = i;

        for(int i = 1; i < word1.size()+1; i++)
        {   
            for(int j = 1; j < word2.size()+1; j++)
            {
                int diagonal = word1[i-1] == word2[j-1] ? dp[i-1][j-1] : dp[i-1][j-1] + 1;
                int left = dp[i][j-1] + 1;
                int up = dp[i-1][j] + 1;
                dp[i][j] = min(diagonal, min(left, up));
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};