class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
      int n = nums.size();
      vector<int>v=nums;
      sort(v.begin(),v.end());
      int temp = v[n-1];
      int count = 0;
      int Maxcount = INT_MIN;
      for(int i=0;i<n;i++)
      {
        if(nums[i] == temp)
        {
            count++;
        }
        else count = 0;
        Maxcount = max(count,Maxcount);
      } 
      return Maxcount; 
    }
};