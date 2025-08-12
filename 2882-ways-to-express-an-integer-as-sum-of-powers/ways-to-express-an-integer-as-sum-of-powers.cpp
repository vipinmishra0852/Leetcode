class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    long long intPow(int base, int exp) {
        long long res = 1;
        for (int i = 0; i < exp; i++) {
            res *= base;
            if (res > 1e9) break;
        }
        return res;
    }

    int helper(int n, int num, int x) {
        if (n == 0) return 1;
        if (n < 0 || num > n) return 0;

        if (dp[n][num] != -1) return dp[n][num];

        long long p = intPow(num, x);
        if (p > n) return dp[n][num] = 0;

        int take = helper(n - p, num + 1, x) % MOD;
        int skip = helper(n, num + 1, x) % MOD;

        return dp[n][num] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return helper(n, 1, x);
    }
};
