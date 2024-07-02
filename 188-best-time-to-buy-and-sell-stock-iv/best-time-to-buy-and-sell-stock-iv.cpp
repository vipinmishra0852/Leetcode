class Solution {
public:
    vector<int>copy;
    int dp[1005][105][2];
    int helper(int i,int k,bool on)
    {
        if(i == copy.size()) return 0;
        if(dp[i][k][on] != -1) return dp[i][k][on];
        int ans = INT_MIN;
        ans = helper(i+1,k,on); // avoid 
        // not avoid
        if(on)
        {
            ans = max(ans,copy[i] + helper(i+1,k-1,false));
        }
        else
        {   if(k>0){
            ans = max(ans,helper(i+1,k,true) - copy[i]);
        }
        }
        return dp[i][k][on]=ans;
    }
    int maxProfit(int k, vector<int>& prices) 
    { copy.clear();
      copy = prices;
      memset(dp,-1,sizeof dp);
      int ans = helper(0,k,false);
      return ans;
    }
};