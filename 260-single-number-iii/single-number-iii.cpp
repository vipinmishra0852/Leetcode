class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_res = 0;
        int k = 0;
        vector<int> v(2, 0);
    
        for (int i = 0; i < n; i++) {
            xor_res ^= nums[i];
        }

        int temp = xor_res;
        while ((temp & 1) == 0) {
            temp = temp >> 1;
            k++;
        }

        int num1 = 0, num2 = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] >> k) & 1) {
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }

        v[0] = num1;
        v[1] = num2;
        
        return v;
    }
};
