class Solution {
public:
    int dp[5005];
    vector<int>copy;
    int n;
    int helper(int idx,int &count)
    {
    if(idx == n-1) return 0;
    if(dp[idx]!=-1) return dp[idx];
    if(copy[idx] - copy[idx-1] == copy[idx+1] - copy[idx]) 
        {
         count++;
        int d = copy[idx+1] - copy[idx];
        for(int i = idx + 1 ; i < n - 1 ; i++)
        {
            if( d == copy[i+1] - copy[i])
            {
                count++;
            }
            else break;
        }
        
        }
        return dp[idx] = helper(idx+1,count); 
    }
    int numberOfArithmeticSlices(vector<int>& nums) 
    {   n = nums.size();
    memset(dp,-1,sizeof(dp));
    int count = 0;
       if(n<3) return 0; 
       int idx = 1;
       copy = nums;
       int ans = helper(idx,count);
       return count;
    }
};