class Solution {
public:
  int m, n;
vector<vector<int>> dp;

int solve(int i, int j, vector<vector<int>>& a) {

    if(i >= m || j >= n) return 1e9;  

    if(i == m-1 && j == n-1)
        return max(1, 1 - a[i][j]);

    if(dp[i][j] != -1) return dp[i][j];

    int down  = solve(i+1, j, a);
    int right = solve(i, j+1, a);

    int need = min(down, right) - a[i][j];

    return dp[i][j] = max(1, need);
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    m = dungeon.size();
    n = dungeon[0].size();
    dp.assign(m, vector<int>(n, -1));
    return solve(0, 0, dungeon);
}

};