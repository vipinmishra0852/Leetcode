class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
     int n = nums.size();
     int flips = 0;
     int flipCountfromPastfori = 0;
     vector<bool>isFlipped(n,false);
     for(int i=0;i<n;i++)
     {
        if(i>=k && isFlipped[i-k]==true)
        {
            flipCountfromPastfori--;
        }
        if(flipCountfromPastfori % 2 == nums[i]) // flip at index i
        {
            if(i + k > n) return -1;
            flipCountfromPastfori++;
            flips++;
            isFlipped[i] = true;
        }
     }
     return flips;
     
     
    }
};