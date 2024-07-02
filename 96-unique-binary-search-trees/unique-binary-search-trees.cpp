class Solution {
public:
    vector<int>dp;
    int helper(int n)
    {
        if(n == 0 || n == 1) return 1;
        if( n == 2) return 2;
        if(dp[n]!=-1) return dp[n];
        int sum = 0;
        for(int k = 1; k<=n ; k++)
        {
            sum += helper(k-1) * helper(n-k);
        } 
        return dp[n] = sum;
    }
    int numTrees(int n)
    {
    dp.clear();
    dp.resize(30,-1);
    int ans = helper(n);
    return ans;
    }
};