class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n)
    {
    vector<vector<int>>ans(m,vector<int>(n,0));
    vector<vector<int>>empty;
    int s = nums.size();
    if(s!=m*n)
    return empty;
    else
    {
        int k=0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0 ; j <n;j++)
            {
             ans[i][j]=nums[k];
             k++;
            }
        }
    }
    return ans;
    }
};