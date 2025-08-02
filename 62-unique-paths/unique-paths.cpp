class Solution {
public:
    int a,b;
    vector<vector<int>>dp;
    int helper(int i,int j)
    {
        if(i < 0 || i >= a || j < 0 || j >= b)
        {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(i == a-1 && j == b-1) return 1;
        return dp[i][j] = (helper(i+1,j) + helper(i,j+1));
    }
    int uniquePaths(int m, int n) 
    {
    dp.resize(m+1,vector<int>(n+1,-1));
    a = m;
    b = n;
    return helper(0,0);    
    }
};