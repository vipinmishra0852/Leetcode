class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid,int &peri)
    {
      if(i < 0 || j < 0 || i >= n || j >= m  || grid[i][j] == 0) 
      {
         peri++;
         return;
      }
      if(grid[i][j] == -1) return;
      grid[i][j] = -1;
      dfs(i+1,j,grid,peri);
      dfs(i-1,j,grid,peri);
      dfs(i,j-1,grid,peri);
      dfs(i,j+1,grid,peri);
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
     n = grid.size();
     m = grid[0].size();
   int peri = 0;
     for(int i = 0 ; i<n;i++)
     {
        for(int j = 0 ; j < m ;j++)
        {
         if(grid[i][j] == 1)
         {
            peri++;
            dfs(i,j,grid,peri);
         }
        }
     }   
     return peri-1;
    }
};