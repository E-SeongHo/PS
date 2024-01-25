class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
//         bool onHand = false;
//         int profit = 0;

//         for(int i = 0; i < prices.size()-1; i++)
//         {
//             if(onHand)
//             {
//                 if(prices[i] > prices[i+1])
//                 {
//                     profit += prices[i];
//                     onHand = false;
//                 }
//             }
//             else
//             {
//                 if(prices[i] < prices[i+1])
//                 {
//                     profit -= prices[i];
//                     onHand = true;
//                 }
//             }
//         }

//         if(onHand) profit += prices.back();
        
        // Simple Version
        
        int profit = 0;
        for(int i = 0; i < prices.size()-1; i++)
            if(prices[i] < prices[i+1]) profit += prices[i+1] - prices[i];
        

        return profit;
    }
};