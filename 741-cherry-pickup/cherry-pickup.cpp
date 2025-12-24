class Solution {
public:
    int n;
    int dp[51][51][51][51];

    int solve(int r1, int c1, int r2, int c2, vector<vector<int>>& grid)
    {
        // Out of bounds
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return -1000000000;

        // Thorn encounter
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1000000000;

        // Destination reached
        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        if(dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];

        int cherries = 0;

        // Same cell -> count once
        if(r1 == r2 && c1 == c2)
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];

        // 4 possible combined moves
        int best = max({
            solve(r1+1, c1, r2+1, c2, grid),   // both down
            solve(r1+1, c1, r2, c2+1, grid),   // A down, B right
            solve(r1, c1+1, r2+1, c2, grid),   // A right, B down
            solve(r1, c1+1, r2, c2+1, grid)    // both right
        });

        cherries += best;

        return dp[r1][c1][r2][c2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));

        int ans = solve(0,0,0,0,grid);
        return max(0, ans);
    }
};
