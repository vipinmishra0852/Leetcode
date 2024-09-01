class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n)
    {
    vector<vector<int>>ans(m,vector<int>(n,0));
    
    int s = nums.size();
    if(s!=m*n)
    return {};
    else
    {
        for(int i = 0;i<m*n;i++)
        {
           ans[i/n][i%n]=nums[i];
        
        }
    }
    return ans;
    }
};