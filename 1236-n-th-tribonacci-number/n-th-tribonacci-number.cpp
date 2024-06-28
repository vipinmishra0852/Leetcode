class Solution {
public:
    int helper(vector<int>&dp,int n)
    {if(n == 0) return 0;
     if(n <=2) return 1;
     if(dp[n] != -1) return dp[n];
     dp[n] = helper(dp,n-1) + helper(dp,n-2) + helper(dp,n-3);
     return dp[n];
    }
    int tribonacci(int n) 
    {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    int ans = helper(dp,n);
    return ans;
    }
};