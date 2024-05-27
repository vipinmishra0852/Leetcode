class Solution {
public:
    int search(vector<int>& nums, int k) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == k) {
                return mid;
            } else if (nums[mid] < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }

    int specialArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int x = 1; x <= n; ++x) {
            int idx = n - x;
            if (nums[idx] >= x && (idx == 0 || nums[idx - 1] < x)) {
                return x;
            }
        }
        return -1;
    }
};
