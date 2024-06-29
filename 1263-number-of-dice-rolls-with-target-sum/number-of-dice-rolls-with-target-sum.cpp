class Solution {
public:
vector<vector<int>>dp;
    int helper(int n,int k,int t)
    {
     if(n==0 && t == 0) return 1;
     if(n == 0) return 0;
     if(dp[n][t] != -1) return dp[n][t];
     int sum = 0;
     for(int i = 1;i<=k;i++)
     {
      if(t-i>=0)
      {
      sum = (sum +  helper(n-1,k,t-i) )%1000000007;
      
      }
     
     }
     dp[n][t] = sum;
     return dp[n][t];
    }
    int numRollsToTarget(int n, int k, int target) 
    {
     dp.resize(n+1,vector<int>(target+1,-1));
    return helper(n,k,target);    
    }
};