class Solution {
public:
    int row;
    int col;
    vector<vector<int>> temp;  // Global temp vector to hold grid values
    vector<vector<int>> dp;

    int helper(int i, int j) {
        // Base case: check if out of bounds
        if (i < 0 || i >= row || j >= col) return 0;
        
        // Return memoized result if already computed
        if (dp[i][j] != -1) return dp[i][j];

        int currentValue = temp[i][j];
        int maxMoves = 0;

        // Move to the right if the next cell value is greater
        if (j + 1 < col && temp[i][j + 1] > currentValue) {
            maxMoves = max(maxMoves, 1 + helper(i, j + 1));
        }
        // Move to the up-right if the next cell value is greater
        if (i - 1 >= 0 && j + 1 < col && temp[i - 1][j + 1] > currentValue) {
            maxMoves = max(maxMoves, 1 + helper(i - 1, j + 1));
        }
        // Move to the down-right if the next cell value is greater
        if (i + 1 < row && j + 1 < col && temp[i + 1][j + 1] > currentValue) {
            maxMoves = max(maxMoves, 1 + helper(i + 1, j + 1));
        }

        // Memoize the result
        dp[i][j] = maxMoves;
        return dp[i][j];
    }

    int maxMoves(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        // Copy grid to the global temp vector
        temp = grid;
        dp = vector<vector<int>>(row, vector<int>(col, -1));
       
        int ans = 0;

        // Start from each cell in the first column
        for (int i = 0; i < row; i++) {
            ans = max(ans, helper(i, 0));
        }

        return ans;
    }
};
