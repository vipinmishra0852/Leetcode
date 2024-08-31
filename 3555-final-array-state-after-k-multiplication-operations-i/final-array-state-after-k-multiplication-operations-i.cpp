class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
    int m = multiplier;
    for(int i=0 ;i<k;i++)
    {
     vector<int>temp = nums;
     sort(temp.begin(),temp.end());
     int n = temp[0];
     temp[0] = temp[0]*m;
     int m = temp[0];
     for(int j = 0 ; j < nums.size();j++)
    {
        if(nums[j] == n) 
        {
            nums[j] = m;
            break;
        }
        
    }
    }    
    return nums;
    }
};