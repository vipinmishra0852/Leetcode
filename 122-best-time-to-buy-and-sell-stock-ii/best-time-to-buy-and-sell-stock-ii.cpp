class Solution {
public:
    vector<int>copy;
    int dp[40000][2];
    int helper(int i,bool on)
    {
        if(i == copy.size()) return 0;
        if(dp[i][on]!=-1) return dp[i][on];
        int ans =INT_MIN;
        ans = max(ans,helper(i+1,on)); // avoid
        if(on)
        {
            ans = max(ans,copy[i] + helper(i+1,false));
        }
        else
        {
            ans = max(ans,helper(i+1,true) - copy[i]);
        }
        return dp[i][on] = ans;
    }
    int maxProfit(vector<int>& prices) 
    {
    copy = prices;
    memset(dp,-1,sizeof dp);
    int ans = helper(0,false);
   return ans;
    }
};