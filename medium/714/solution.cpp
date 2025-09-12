class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;

        long long cash = 0;                 // best profit when NOT holding a stock
        long long hold = -prices[0];        // best profit when holding a stock

        for (int i = 1; i < prices.size(); ++i) {
            long long p = prices[i];
            long long prevCash = cash;      // store yesterday's cash for the buy transition

            // Option 1: stay cash, or sell today (pay fee on sell)
            cash = max(cash, hold + p - fee);

            // Option 2: stay holding, or buy today using yesterday's cash
            hold = max(hold, prevCash - p);
        }

        return cash; // best profit is when we end NOT holding
    }
};

