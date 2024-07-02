class Solution {
public:
    int m,n,ans;
    vector<vector<int>>copygrid,dp;
    int helper(int i,int j)
    {
        if(i >= n || j >= m || i < 0 || j < 0) return INT_MAX;
        if(i == n-1 && j == m-1) return copygrid[n-1][m-1];
        if(dp[i][j] != -1) return dp[i][j];
        ans = copygrid[i][j] + min( helper(i+1,j) , helper(i,j+1) );
        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid)
    {
      n = grid.size();
      m = grid[0].size();
     copygrid = grid;
     dp.clear();
     dp.resize(250,vector<int>(250,0));
     if(m == 1 && n  == 1) return grid[m-1][n-1];
    //  int i = 0;
    //  int j = 0;
    //  int newans = 0;
    //  newans =  helper(0,0);
     dp[n-1][m-1] = grid[n-1][m-1];
     for(int i = n - 2 ; i >= 0 ; i--)
     {
        dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
     }
      for(int i = m - 2 ; i >= 0 ; i--)
     {
        dp[n-1][i] = grid[n-1][i] + dp[n-1][i+1];
     }
     for(int  i = n-2 ; i>= 0 ; i--)
     {
        for(int j = m-2 ; j >= 0 ; j--)
        {
            dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
        }
     }
     

    return dp[0][0];  
    }
};