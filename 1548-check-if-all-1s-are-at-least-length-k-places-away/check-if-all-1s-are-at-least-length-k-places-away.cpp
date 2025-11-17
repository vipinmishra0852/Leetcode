class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
    int n = nums.size();
    bool oneMila = false;
    int count = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(oneMila && nums[i] == 0) count++;
        else if(!oneMila && nums[i] == 1)
        {
            oneMila = true;
        }
        else if(oneMila && nums[i] == 1)
        {
            if(count < k) return false;
            count = 0; 
        }
    }
    return true;
    }
};