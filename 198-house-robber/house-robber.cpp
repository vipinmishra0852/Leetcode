class Solution {
public:
    int n;
    vector<int>dp;
    vector<int>temp;
    int helper(int idx)
    {
        if(idx < 0 ) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = temp[idx] + helper(idx-2);
        int not_pick = helper(idx-1);
        return dp[idx]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
    n = nums.size();
    dp.resize(n,-1);
    // temp = nums;
    // helper(n-1);
    dp[0] = nums[0];
    int prev1 = nums[0];
    int curr = 0;
    int prev2=0;
    for(int idx = 1 ; idx < n ; idx++)
    {
        int pick = nums[idx];
        if( idx-2 >= 0 ) pick+=prev2;
        int not_pick = prev1;
        curr = max(pick,not_pick);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1; 
    }
};