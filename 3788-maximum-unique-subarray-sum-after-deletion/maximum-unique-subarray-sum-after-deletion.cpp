class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
    int n = nums.size();
    map<int,int>mp;
    for(int i = 0 ; i < n ; i++)
    {
        mp[nums[i]]++;
    }
    int ans = -1000;
    int minans = -1000;
    for(auto it:mp)
    {
        if(it.first > 0) 
        {
            ans += it.first;
        }
        else
        {
            minans = max(minans,it.first);
        }
    }
    if(ans == -1000) return minans;
    return ans+1000;

    }
};