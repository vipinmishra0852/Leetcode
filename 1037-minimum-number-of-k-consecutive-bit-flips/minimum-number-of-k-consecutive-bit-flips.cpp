class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipCountfromPastfori = 0;
        vector<bool> isFlipped(n, false);

        for (int i = 0; i < n; i++) {
            if (i >= k && isFlipped[i - k]) {
                flipCountfromPastfori--;
            }

            bool needsFlip = false;
            if (flipCountfromPastfori % 2 == 0) {
                if (nums[i] == 0) {
                    needsFlip = true;
                }
            } else {
                if (nums[i] == 1) {
                    needsFlip = true;
                }
            }

            if (needsFlip) {
                if (i + k > n) return -1;

                flipCountfromPastfori++;
                flips++;
                isFlipped[i] = true;
            }
        }

        return flips;
    }
};
