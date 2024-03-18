class Solution {
public:
    bool check(int mid, vector<int>& piles, int h) {
        long long count = 0; // Use long long to avoid overflow
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            if (mid >= piles[i]) {
                count++;
            } else if (piles[i] % mid == 0) {
                count += piles[i] / mid;
            } else {
                count += piles[i] / mid + 1;
            }
        }
        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = *max_element(piles.begin(), piles.end());
        int lo = 1;
        int hi = max;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, piles, h)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
