class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
     int n = nums.size();
     vector<int>prefix(n,0);
     prefix[0] = nums[0];
     for(int i=1;i<n;i++)
     {
      prefix[i] = prefix[i-1] + nums[i];
     }
     int count = 0;
     unordered_map<int,int>m;
     for(int i=0;i<n;i++)
     {
        if(prefix[i]==k)
        {
            count++;
        }
        int rem = prefix[i] - k;
        if(m.find(rem) != m.end()) count+=m[rem];
        m[prefix[i]]++;

     }
 return count;
    }
};