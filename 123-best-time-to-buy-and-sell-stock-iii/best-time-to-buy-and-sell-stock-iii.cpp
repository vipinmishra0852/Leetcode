class Solution {
public:
    int dp[100005][3][2];
    vector<int>copy;

    int helper(int i,int k,bool on)
    {
        if(i == copy.size()) return 0;
        if(dp[i][k][on] != -1) return dp[i][k][on];
        int ans = INT_MIN;
        ans = max(ans,helper(i+1,k,on)); // avoid
        // not avoid 
        if(on)
        {
        ans = max(ans,copy[i] + helper(i+1,k,false));
        }
        else
        {
            if(k>0)
            {
                ans = max(ans,helper(i+1,k-1,true) - copy[i]);
            }
        }
        return dp[i][k][on] = ans;
    }
    int maxProfit(vector<int>& prices) 
    {
      copy = prices;
      memset(dp,-1,sizeof dp);
      int ans = helper(0,2,false);
      return ans;  
    }
};