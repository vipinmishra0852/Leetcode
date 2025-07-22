class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int i = 0, j = 0, n = nums.size();
        int sum = 0, maxSum = 0;
        
        while (j < n) {
            if (seen.find(nums[j]) == seen.end()) {
                seen.insert(nums[j]);
                sum += nums[j];
                maxSum = max(maxSum, sum);
                j++;
            } else {
                seen.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
        }
        
        return maxSum;
    }
};
