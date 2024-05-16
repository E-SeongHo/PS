class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // I might come up with two approaches : dp and greedy 
        
        vector<int> table(amount+1, -1);
        
        table[0] = 0;
        
        for(int i = 1; i < table.size(); i++)
        {
            for(auto coin : coins)
            {
                if(i - coin < 0 || table[i-coin] == -1) continue;
                
                if(table[i] == -1) table[i] = table[i-coin] + 1;
                else table[i] = min(table[i], table[i-coin] + 1);
            }
        }
        
        return table[amount];
    }
};