class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
    int n  = nums.size();
    int po = 0;
    int ne = 0;
    for(int i = 0 ; i < n;i++)
    {
        if(nums[i] > 0 )po++;
        if(nums[i] < 0) ne++;

    }   
    return max(po,ne); 
    }
};