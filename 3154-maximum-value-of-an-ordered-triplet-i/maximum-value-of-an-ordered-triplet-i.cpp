class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
    int n = nums.size();
     vector<int>prefix(n,0);
     prefix[0] = nums[0];
     for(int i = 1 ; i <n;i++)
     {
      prefix[i] = max(prefix[i-1],nums[i]);
     }
     long long ans = 0;
      for(int j = 1 ; j < n-1 ;j++)
      {
         for(int k = j+1 ; k < n ; k++)
         {
           if(prefix[j-1] > nums[j])
           {
            long long temp =(long long)(prefix[j-1] - nums[j] )* (long long)nums[k];
            ans = max(ans,temp);
           }
         }
      }
     
     return ans;
    }
};