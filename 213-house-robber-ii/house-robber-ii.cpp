class Solution {
public:
    int rob(vector<int>& nums) 
    {
    int n = nums.size();
    vector<int>dp(n+1,0);
    vector<int>dp1(n+1,0);    
    dp[0]=nums[0];
    for(int idx = 1 ; idx < n ; idx++)
    {
        int pick = 0;
        idx != n-1 ?  pick = nums[idx] : pick = 0;
        if(idx - 2 >=0 ) pick+= dp[idx-2];
        int not_pick = dp[idx-1];
        dp[idx] = max(pick,not_pick);
    }
     for(int idx = 1 ; idx < n ; idx++)
    {
        int pick = nums[idx];
        if(idx - 2 >=0 ) pick+= dp1[idx-2];
        int not_pick = dp1[idx-1];
        dp1[idx] = max(pick,not_pick);
    }
    return max(dp[n-1],dp1[n-1]);
    }
};