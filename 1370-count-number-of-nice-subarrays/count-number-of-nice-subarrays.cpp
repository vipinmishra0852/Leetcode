class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> copy = nums;

        for (int i = 0; i < n; ++i) {
            copy[i] = (nums[i] % 2 == 0) ? 0 : 1;
        }

        unordered_map<int, int> prefixCount;
        int currentSum = 0;
        int result = 0;

        prefixCount[0] = 1;

        for (int i = 0; i < n; ++i) {
            currentSum += copy[i];
            if (prefixCount.find(currentSum - k) != prefixCount.end()) {
                result += prefixCount[currentSum - k];
            }
            prefixCount[currentSum]++;
        }

        return result;
    }
};