class Solution {
public:
    int n;
    vector<int>dp;
    vector<int>temp;
    int helper(int idx)
    {
        if(idx >=n ) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = temp[idx] + helper(idx+2);
        int not_pick = helper(idx+1);
        return dp[idx]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
    n = nums.size();
    dp.resize(n,-1);
    temp = nums;
    helper(0);
    return dp[0]; 
    }
};