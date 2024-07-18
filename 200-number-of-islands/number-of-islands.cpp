class Solution {
public:
    int n,m;
    
    void dfs(int i,int j,vector<vector<char>>&grid)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || grid[i][j] == '$' ) return;
        grid[i][j] = '$';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid)
    {
      n = grid.size();
      m = grid[0].size();
      int result = 0;
      for(int i= 0 ;i < n; i++)
      {
        for(int j = 0; j < m ; j++)
        {
            if(grid[i][j] == '1')
            {
                result++;
                dfs(i,j,grid);
            }
        }
      }  
      return result;
    }
};