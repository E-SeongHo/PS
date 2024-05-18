class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyIdx = 0;
        int profit = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i]-prices[buyIdx]);
            buyIdx = prices[i] < prices[buyIdx] ? i : buyIdx;
        }        
        
        return profit;
    }
};