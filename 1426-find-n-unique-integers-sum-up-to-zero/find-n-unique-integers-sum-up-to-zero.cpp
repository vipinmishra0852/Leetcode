class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        // if odd, include 0
        if(n % 2 == 1) {
            v.push_back(0);
            n--;  // remaining numbers to fill
        }
        // add pairs
        for(int i = 1; i <= n/2; i++) {
            v.push_back(i);
            v.push_back(-i);
        }
        return v;
    }
};
