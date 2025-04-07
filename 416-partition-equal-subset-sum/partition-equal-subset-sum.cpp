class Solution {
public:
    vector<vector<int>>dp;
    bool helper(vector<int>&nums,int i,int target)
    {
        if(target < 0 || i >= nums.size()) return false;
        if(target == 0) return true;
        if(dp[i][target] != -1) return dp[i][target];
       return dp[i][target] = (helper(nums,i+1,target-nums[i]) || helper(nums,i+1,target));
        
    }
    bool canPartition(vector<int>& nums) 
    {
     int n = nums.size();
     
     int sum=accumulate(nums.begin(),nums.end(),0);   
     if(sum%2 != 0) return false;
     int target = sum/2;
     dp.resize(n+1,vector<int>(target+1,-1));
     return helper(nums,0,target) ;
    }
};