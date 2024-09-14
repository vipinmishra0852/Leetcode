class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxElement = *max_element(nums.begin(), nums.end());
        int count = 0, maxCount = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == maxElement) {
                count++;
            } else {
                count = 0;
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
