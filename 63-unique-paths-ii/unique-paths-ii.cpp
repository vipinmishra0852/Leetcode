class Solution {
public:
    int n,m;
    vector<vector<int>>grid,dp;
    int f(int i,int j)
    {   if(i < 0 || j < 0 || i >=n || j >= m) return 0;
        if(grid[i][j] == 1) return 0;   
        if( i == n-1 && j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i,j+1) + f(i+1,j); 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
      grid = obstacleGrid;
      n = grid.size();
      m = grid[0].size();
      dp.clear();
      dp.resize(105,vector<int>(105,-1));
      if(grid[n-1][m-1] == 1) return 0;
      return f(0,0);  
    }
};