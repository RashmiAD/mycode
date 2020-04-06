class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
        
        int max_profit = 0;
        
        for(int i = 0; i < prices.size() - 1; i++)
        {
            int profit = prices[i+1] - prices[i];
            if(profit > 0)
                max_profit += profit;
        }
        
        return max_profit;
    }
};
