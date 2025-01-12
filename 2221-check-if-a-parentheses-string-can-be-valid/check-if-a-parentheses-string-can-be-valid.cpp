class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;  // Can't be valid if odd length
        
        int open_count = 0, close_count = 0;
        
        // First pass: check from left to right
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || locked[i] == '0') {
                open_count++;
            } else {
                close_count++;
            }
            
            if (close_count > open_count) return false;
        }
        
        // Second pass: check from right to left
        open_count = close_count = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || locked[i] == '0') {
                close_count++;
            } else {
                open_count++;
            }
            
            if (open_count > close_count) return false;
        }
        
        return true;
    }
};
