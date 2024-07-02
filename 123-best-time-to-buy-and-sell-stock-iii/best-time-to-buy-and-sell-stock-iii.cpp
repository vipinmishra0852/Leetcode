class Solution {
public:
    int dp[100005][3][2];
    vector<int> copy;

    int helper(int i, int k, bool on) {
        if (i == copy.size()) return 0;
        if (dp[i][k][on] != -1) return dp[i][k][on];
        int ans = 0; // Initialize ans to 0 to avoid negative values in max calculation
        ans = max(ans, helper(i + 1, k, on)); // Avoid the current day
        
        if (on) {
            // If holding a stock, consider selling it
            ans = max(ans, copy[i] + helper(i + 1, k, false));
        } else {
            // If not holding a stock, consider buying it
            if (k > 0) {
                ans = max(ans, helper(i + 1, k - 1, true) - copy[i]);
            }
        }
        return dp[i][k][on] = ans;
    }

    int maxProfit(vector<int>& prices) {
        copy = prices;
        memset(dp, -1, sizeof(dp));
        return helper(0, 2, false); // Start with day 0, 2 transactions allowed, and not holding a stock
    }
};