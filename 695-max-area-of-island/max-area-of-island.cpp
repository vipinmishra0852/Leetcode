class Solution {
public:
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i < 0 || j < 0 || i >= n || j >= m  || grid[i][j] != 1) return 0;
        grid[i][j] = 0;
        return 1 + dfs(i+1,j,grid) +  dfs(i-1,j,grid) + dfs(i,j+1,grid) + dfs(i,j-1,grid); 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
         int ans = 0;
        for(int i = 0 ; i  < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                   int area = dfs(i,j,grid);
                   ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};