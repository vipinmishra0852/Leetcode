class Solution {
public:
    double dp[30][30][105];
    int attempt;
    int size;
    double move(int i,int j,int k)
    {
        if(i < 0 || j < 0 || i >=size || j >= size) return 0.0;
        if(k == 0) return 1.0;
        if(dp[i][j][k] > -0.9) return dp[i][j][k];
        double result = ( move(i-2,j+1,k-1) + move(i-2,j-1,k-1) + move(i+2,j+1,k-1) + move(i+2,j-1,k-1) + move(i-1,j-2,k-1) + move(i+1,j-2,k-1) + move(i-1,j+2,k-1) + move(i+1,j+2,k-1) ) / 8;
        return dp[i][j][k] = result;
    }
    double knightProbability(int n, int k, int row, int column) 
    {
     size = n;
     memset(dp,-1,sizeof dp);
     int i = row;
     int j = column;
     double result = move(i,j,k);
     return result;
    }
};