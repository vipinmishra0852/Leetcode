class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
     int countZ=0;
     int countO=0;
     int countT=0;
     int n=nums.size();
     for(int i=0;i<n;i++)
     {
        if(nums[i]==0) countZ++;
        else if(nums[i]==1) countO++;
        else countT++;
     } 
       
     for(int i=0;i<countZ;i++)
     {
        nums[i]=0;
     }
      for(int i=countZ;i<countZ+countO;i++)
     {
        nums[i]=1;
     }
      for(int i=countZ+countO;i<countZ+countO+countT;i++)
     {
        nums[i]=2;
     }
     
    }
};