class Solution {
public:
    int numSub(string s) 
    {
        int n = s.length();
        long long count = 0;
        long long ans = 0;
        const long long MOD = 1000000007;
        const long long inv2 = 500000004; 

        for (int i = 0; i < n; i++) 
        {
            if (s[i] == '1') count++;
            else 
            {
                ans = (ans + (count % MOD * (count + 1) % MOD) % MOD * inv2 % MOD) % MOD;
                count = 0;
            }
        }

      
        if (s[n - 1] == '1') {
            ans = (ans + (count % MOD * (count + 1) % MOD) % MOD * inv2 % MOD) % MOD;
        }

        return ans;
    }
};
