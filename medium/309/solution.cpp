
//solved by dynamic programming
//track the maximum profit we can
//make any day based on the decision
//made the previous day (temp vars)
//(if cooldown was longer/some other condition
//was in place, we would have to track more days back)

//at any day, we can do 1 of 3:
//  buy
//  sell
//  nothing (on cooldown)

//run over all days and track
//max profit we could achieve
//with these actions
//then return total max

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int buy = -prices[0];  // Max profit if holding a stock
        int sell = 0;          // Max profit if just sold a stock
        int cooldown = 0;      // Max profit if in cooldown
        // (all at current day)
        
        for (int i = 1; i < n; i++) {
            
            //because of cooldown
            //and buy/sell rules
            //we need to look back
            //one day
            int prev_buy = buy;
            int prev_sell = sell;
            int prev_cooldown = cooldown;
            
            //update
            buy = max(prev_buy, prev_cooldown - prices[i]);
            sell = prev_buy + prices[i];
            cooldown = max(prev_cooldown, prev_sell);
        }
        return max(sell, cooldown);
    }
};

