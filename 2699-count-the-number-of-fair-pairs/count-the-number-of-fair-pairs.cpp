#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            int left = i + 1;
            int right = n - 1;

            int low_bound = std::lower_bound(nums.begin() + left, nums.end(), lower - nums[i]) - nums.begin();
            int high_bound = std::upper_bound(nums.begin() + left, nums.end(), upper - nums[i]) - nums.begin() - 1;

            if (low_bound <= high_bound && low_bound < n) {
                count += high_bound - low_bound + 1;
            }
        }

        return count;
    }
};
