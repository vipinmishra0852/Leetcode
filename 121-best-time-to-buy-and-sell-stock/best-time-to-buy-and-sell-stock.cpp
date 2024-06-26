
class Solution {
public:
    int dp[100005];
    int helper(vector<int>& prices, int i, int minPrice) {
        if (i == prices.size()) return 0;
        if(dp[i] != -1) return dp[i];
        // Calculate profit if we sell at the current price
        int profit = prices[i] - minPrice;
        
        // Update the minimum price
        minPrice = min(minPrice, prices[i]);
        
        // Either sell at the current price or skip to the next day
        return dp[i] = max(profit, helper(prices, i + 1, minPrice));
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        memset(dp,-1,sizeof dp);
        return helper(prices, 0, prices[0]);
    }
};