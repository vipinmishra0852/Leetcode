class Solution {
public:
    int n ;
    int dp[101];
    int add(int idx,vector<int>&nums)
    {
        if(idx >= n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int sum = nums[idx] + add(idx+2,nums);
        int sum2 = add(idx+1,nums);
        return (dp[idx] = max(sum,sum2));
    }
    int rob(vector<int>& nums) 
    {
     
     n = nums.size(); 
     memset(dp,-1,sizeof(dp));

    if(n == 1) return nums[0];
    if(n == 2) return *max_element(nums.begin(),nums.end());
    return add(0,nums); 
    }
};