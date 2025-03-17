class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     map<int,int>mp;
     for(int ele:nums)
     {
        mp[ele]++;
     }
     for(auto it:mp)
     {
        if(it.second % 2 != 0) return false;
     }
     return true;
    }
};