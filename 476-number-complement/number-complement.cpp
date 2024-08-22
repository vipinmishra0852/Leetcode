class Solution {
public:
    int findComplement(int num) 
    {
        unsigned int x = static_cast<unsigned int>(num);
        int n = floor(log2(x)) + 1;
        
        unsigned int t = (1U << n) - 1;
        
        int ans = num ^ t;
        
        return ans;
    }
};
