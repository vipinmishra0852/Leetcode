class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        // If the starting point has an obstacle, return 0 as there's no way to start.
        if (arr[0][0] == 1) return 0;

        // Initialize the dp array with 0s
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Set the starting point
        dp[0][0] = 1;

        // Fill the dp array
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If there's an obstacle, skip the cell
                if (arr[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    // If not in the first row, add paths from the top cell
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    // If not in the first column, add paths from the left cell
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};