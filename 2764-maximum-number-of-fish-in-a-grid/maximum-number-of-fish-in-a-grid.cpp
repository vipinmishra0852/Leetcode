class Solution {
public:
    int n ;
    int m;
    int dfs(int i,int j,vector<vector<int>>&grid)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        return (temp + dfs(i,j+1,grid) + dfs(i,j-1,grid) + dfs(i-1,j,grid) + dfs(i+1,j,grid));
        
    }
    int findMaxFish(vector<vector<int>>& grid) 
    {
     n = grid.size();
     m = grid[0].size();
     int max_ans = 0;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < m;j++)
        {
            if(grid[i][j] > 0)
            {
                max_ans = max(max_ans,dfs(i,j,grid));
            }
        }
    }    
     return max_ans;
    }
   
};