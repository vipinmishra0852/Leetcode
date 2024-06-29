class Solution {
public:
    int helper(vector<int>& nums, int idx, int n,vector<int>&dp) {
        if (idx >= n) return 0;
        if (idx == n - 1) return nums[n - 1];
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = nums[idx] + max(helper(nums, idx + 2, n,dp), helper(nums, idx + 3, n,dp));
        return dp[idx]; 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int>dp(n,-1);
        int idx = 0;
        return max(helper(nums, idx, n,dp), helper(nums, idx + 1, n,dp));
    }
};
