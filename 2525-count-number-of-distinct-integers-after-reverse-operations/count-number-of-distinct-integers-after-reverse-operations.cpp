class Solution {
public: 
    int reverseInt(int n)
    { int digit=0;
      while(n>0)
      {
       int rem=n%10;
       digit = rem+digit*10;
       n=n/10;
      }
      return digit;
    }
    int countDistinctIntegers(vector<int>& nums) 
    {
      int n=nums.size();
      vector<int>reverse;
      for(int i=0;i<n;i++)
      {
       reverse.push_back(reverseInt(nums[i]));
      } 
      for(int i=0;i<n;i++)
      { 
        int x = reverse[i];
        nums.push_back(x);
      } 
     set<int>s;
     for(int i=0;i<nums.size();i++)
     {
        s.insert(nums[i]);
     }
     return s.size();
    }
};