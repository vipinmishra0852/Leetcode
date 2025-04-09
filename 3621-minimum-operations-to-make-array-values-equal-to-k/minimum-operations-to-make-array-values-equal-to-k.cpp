class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       map<int,int>mp;
       int n = nums.size();
       sort(nums.begin(),nums.end());
       if(nums[0] < k) return -1;
       int ans = 0;
       for(int i = 0 ; i < n ; i++)
       {
        mp[nums[i]]++;
       } 
       int m = mp.size();
       if(k < nums[0]) return m;
       return m-1;
       

    }
};