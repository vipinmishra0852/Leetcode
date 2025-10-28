class Solution {
public:
    int countValidSelections(vector<int>& nums) 
    {
    int n = nums.size();
    vector<int>pre(n,0);
    pre[0] = nums[0];
    vector<int>suf(n,0);
    suf[n-1] = nums[n-1];
    int count = 0;
    for(int i = 1 ; i <  n ; i++)
    {
        pre[i]=pre[i-1] + nums[i];
    }
    for(int i = n-2 ; i >= 0 ; i--)
    {
        suf[i] = suf[i+1]+ nums[i];
    } 
    for(int i = 0 ;i < n;i++)
    {
        if(nums[i] == 0 && pre[i] == suf[i])
        {
          count+=2;
        }
        else if(nums[i] == 0 && abs(pre[i]-suf[i]) == 1) count++;
    }
    return count;
    }
};