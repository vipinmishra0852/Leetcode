class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int sum = nums[0], ans = nums[0];
        int j = 1;

        while (j < n) {
            if (nums[j] > nums[j - 1]) {
                sum += nums[j];  // Continue adding to the current sequence
            } else {
                ans = max(ans, sum);  // Update the max sum
                sum = nums[j];  // Start a new sequence
            }
            j++;  // Move to the next element
        }

        return max(ans, sum);  // Ensure the last sequence is considered
    }
};
