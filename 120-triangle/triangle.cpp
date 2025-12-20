class Solution {
public:
    vector<vector<int>> temp;
    vector<vector<int>>dp;
    int helper(int row,int col)
    {
        if(row < 0 || col < 0 || col >= temp[row].size()) return 1e9;
        if(row == 0 && col == 0) return temp[row][col];
        if(dp[row][col] != -1)return dp[row][col];
        int thoda_idhar = temp[row][col] + helper(row-1,col-1);
        int thoda_udhar = temp[row][col] + helper(row-1,col);
        return dp[row][col] = min(thoda_idhar,thoda_udhar);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      int m = triangle[n-1].size();  
      dp.resize(n,vector<int>(n,-1));
      temp = triangle;
      int ans = INT_MAX;
      for(int i = 0 ; i < m ; i++)
      {
        ans = min(ans,helper(n-1,i));
      }
      return ans;
    }
};