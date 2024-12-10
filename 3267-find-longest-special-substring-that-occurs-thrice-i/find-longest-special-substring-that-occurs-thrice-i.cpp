class Solution {
public:
    int maximumLength(string s) 
    {
        int n = s.size();
        vector<string> v;
        int i = 0;
        while (i < n) {
            string str = "";
            for (int j = i; j < n; j++) {
                str = str + s[j];
                v.push_back(str);
                if (j + 1 < n && s[j] != s[j + 1]) { 
                    break;
                }
            }
            i++;
        }
        map<string, int> m;
        for (int i = 0; i < v.size(); i++) {
            m[v[i]]++;
        }
        int ans = -1;
        for (auto it : m) {
            if (it.second >= 3) {
                ans = max(ans, static_cast<int>(it.first.size())); 
            }
        }
        return ans;
    }
};
