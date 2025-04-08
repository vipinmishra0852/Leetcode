class Solution {
public:
    bool isdouble(vector<int>&nums,int start)
    {
     map<int,int>mp;
     for(int i = start ; i < nums.size() ; i++)
     {
        mp[nums[i]]++;
     }  

      for(auto it:mp)
     {
        if(it.second > 1)
        {
         return true;
        }
     }
    return false;
    }

   
    int minimumOperations(vector<int>& nums) 
    {
     int ans = 0;
     int n = nums.size();
     int i = 0;
     for(int j = 0 ; j < n+1/3 ; j++)
     {
     if(isdouble(nums,i))
     {
        ans++;
        i = i+3;
     }
     else continue;
     }
     return ans;


    }
};