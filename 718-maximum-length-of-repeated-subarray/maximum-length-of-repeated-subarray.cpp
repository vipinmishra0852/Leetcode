class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<int> copy1;
    vector<int> copy2;

    int solve(int i, int j) {
        if (i == n || j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if (copy1[i] == copy2[j]) {
            ans = 1 + solve(i + 1, j + 1);
        }
        
        solve(i + 1, j);
        solve(i, j + 1); 

        return dp[i][j] = ans;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        copy1 = nums1;
        copy2 = nums2;
        n = nums1.size();
        m = nums2.size();

        dp = vector<vector<int>>(n, vector<int>(m, -1));
        
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxLength = max(maxLength, solve(i, j));
            }
        }

        return maxLength;
    }
};
