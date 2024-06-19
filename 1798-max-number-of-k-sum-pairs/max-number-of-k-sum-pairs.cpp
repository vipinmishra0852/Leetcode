class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
     map<int,int>m;
     for(int i= 0;i<nums.size();i++)
     {
        m[nums[i]]++;
     } 
     int count = 0;
     for(auto x:nums)
     {
        int diff = k-x;
        if(diff == x)
        {
            count+=(m[diff]/2);
            m.erase(x);
        }
        else if(m.count(diff))
        {
            count+=min(m[diff],m[x]);
            m.erase(x);
            m.erase(diff);
        }
     }
     return count;
    }
};