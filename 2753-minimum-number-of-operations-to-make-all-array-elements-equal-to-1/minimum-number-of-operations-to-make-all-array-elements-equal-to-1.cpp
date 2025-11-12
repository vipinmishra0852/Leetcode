class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
    int n = nums.size();
    int operations = INT_MAX;
    int countOne = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(nums[i] == 1) countOne++;
    }    
    if(countOne > 0)
    {
        return n - countOne;
    }
    else
    {
       
        for(int i = 0 ; i<n-1 ; i++)
        {
          int gcd = nums[i];
         for(int j = i + 1; j < n ; j++)
         {
           gcd = __gcd(gcd,nums[j]);
           if(gcd == 1)
           {
            operations = min(operations,j-i + n-1);
           } 
         }
        }
        if(operations == INT_MAX) return -1;
        return operations;
    }
    }
};