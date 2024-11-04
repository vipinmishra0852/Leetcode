class Solution {
public:
    string compressedString(string word) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n = word.size();
        if (n == 0) return "";
        
        string ans = "";
        int count = 1;
        
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                count++;
                if (count == 10) {
                    ans += "9";
                    ans += word[i - 1];
                    count = 1;
                }
            } else {
                ans += to_string(count);
                ans += word[i - 1];
                count = 1;
            }
        }
        
        ans += to_string(count);
        ans += word[n - 1];
        
        return ans;
        
    }
};