class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) 
    {
    int n = nums.size();
    int len = INT_MAX;
    int i=0;
    int j=0;
    int sum = 0;
    while(i < n)
    { 
        sum = sum + nums[i];
        while(sum >= k)
        {
            
        len=min(len,i-j+1);
        sum = sum - nums[j];
        j++;   
        }
      i++;  
        
    }

/*
    for(int i =0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
        sum = sum+nums[j];
        if(sum >= k)
        {
        len = min(len,j-i+1);
        break;
        }
        }
    } */
    return (len == INT_MAX)?0:len;    
    }
};