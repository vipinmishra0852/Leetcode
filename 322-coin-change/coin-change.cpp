class Solution {
public:
    vector<int>coinCopy;
    vector<vector<int>>dp;
    int fn(int amount,int idx)
{
        if(idx == 0)
        {
            if(amount % coinCopy[idx] == 0) return amount/coinCopy[idx];
            else return 1e9;
        }
        if(dp[amount][idx] != -1) return dp[amount][idx];
        int not_pick = fn(amount,idx-1);
        int pick = 1e9;
        if(coinCopy[idx] <= amount)
        {
            pick = 1 + fn(amount-coinCopy[idx],idx);
        }
        return dp[amount][idx] = min(pick, not_pick);

    }
    int coinChange(vector<int>& coins, int amount) {
        coinCopy = coins;
        int n = coins.size();
        dp.resize(amount+1,vector<int>(n+1,-1));
        int ans = fn(amount,n-1);
        if(ans == 1e9) return -1;
        return ans;
    }
};