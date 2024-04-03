class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        long long ans = 1;
        int countZero = 0;
        int zeroIndex = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                countZero++;
                zeroIndex = i;
                continue;
            }
            ans *= nums[i];
        }

        vector<int> result(n, 0);

        if (countZero > 1) {
            return result; 
        }

        if (countZero == 1) {
            result[zeroIndex] = ans;
            return result;
        }

        for (int i = 0; i < n; i++) {
            result[i] = ans / nums[i];
        }

        return result;
    }
};