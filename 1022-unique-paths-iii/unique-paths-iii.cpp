class Solution {
public:
    int n,m;
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int helper(int i,int j,vector<vector<int>>&grid,int ans,int cnt)
    {   int totalpaths = 0;
        if( i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1)
        {
            return 0;
        }
        if(grid[i][j] == 2 && cnt == 0) return 1;
        int temp = grid[i][j];
        grid[i][j] = -1;
        for(auto dir:directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            totalpaths += helper(i_,j_,grid,ans,cnt-1);
        }
        grid[i][j] = temp;
        return totalpaths;

    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
    n = grid.size();
    m = grid[0].size();
    int ans = 0;
    int cnt = 0;
    int i_=0;
    int j_=0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
           if(grid[i][j] == 0)
           {
            cnt++;
           }
           else if(grid[i][j] == 1) 
           {
            i_ = i;
            j_ = j;
           }
        }
    }
    ans = helper(i_,j_,grid,0,cnt+1);
    return ans;
    }
};