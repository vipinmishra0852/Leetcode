class Solution {
public:
    #define ll long long
    ll check(int mid,vector<int>&nums)
    {
        ll sum = 0;
        for(int i = 0; i<nums.size();i++)
        {
            if(nums[i] % mid == 0) {sum = sum + nums[i]/mid;}
            else {sum = sum + ((nums[i]/mid) + 1);}
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& nums, int h) 
    {
     sort(nums.begin(),nums.end());
     ll lo = 1;
     ll hi = nums[nums.size()-1];
     ll ans = hi;
     while(lo <= hi)
     {
       ll mid = lo + ((hi-lo)/2);
        if(check(mid,nums) <= h)
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
     }
     return (int)ans;
    }
};