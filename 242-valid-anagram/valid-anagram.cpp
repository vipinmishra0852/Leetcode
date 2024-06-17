class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> m1, m2;
        
        // Count frequencies of characters in s and t
        for (char ch : s) {
            m1[ch]++;
        }
        
        for (char ch : t) {
            m2[ch]++;
        }
        
        // Compare the frequency maps
        return m1 == m2;
    }
};