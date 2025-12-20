class Solution {
public:
    int n;
    vector<vector<int>>temp;
    vector<vector<int>>dp;
    int helper(int row,int col)
    {
     if(col < 0 || col >= n || row < 0) return 1e9;
     if(row == 0) return temp[row][col];
     if(dp[row][col] != -1) return dp[row][col];
     int thoda_idhar = temp[row][col] + helper(row-1,col-1); 
     int thoda_udhar = temp[row][col] + helper(row-1,col+1);
     int neeche = temp[row][col] + helper(row-1,col);
     return dp[row][col] = min(thoda_idhar,min(thoda_udhar,neeche));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
    n = matrix.size();
    dp.resize(n+1,vector<int>(n+1,0));
    // temp = matrix;
    // int ans = 1e9;
    for(int i = 0 ; i < n;i++)
    {
     for(int j = 0 ; j < n ; j++)
     {
     if(i == 0) dp[i][j] = matrix[i][j];
     else {
     int thoda_idhar = 1e9;
     int thoda_udhar = 1e9;
     int neeche = 1e9;
     if(i > 0 && j > 0) thoda_idhar = matrix[i][j] + dp[i-1][j-1];
     if(i > 0 && j + 1 < n) thoda_udhar = matrix[i][j] + dp[i-1][j+1];
     if(i > 0) neeche = matrix[i][j] + dp[i-1][j];
     dp[i][j] = min(thoda_idhar,min(thoda_udhar,neeche));
     }
     }
    } 
    int ans = 1e9;
    for(int j = 0; j < n; j++)
    ans = min(ans, dp[n-1][j]);
    return ans;
    }
};