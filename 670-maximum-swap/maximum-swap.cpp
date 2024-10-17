class Solution {
public:
    vector<int>v;
    
    void digits(int x) {
        while (x > 0) {
            int d = x % 10;
            x = x / 10;
            v.push_back(d);
        }
        sort(v.begin(), v.end(), greater<int>());
    }

    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        digits(num);
        
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (str[i] != to_string(v[i])[0]) {
                char c = str[i];
                char f = to_string(v[i])[0];
                
                for (int j = n - 1; j >= 0; j--) {
                    if (str[j] == f) {
                        idx = j;
                        break;
                    }
                }
                
                if (idx != -1) {
                    str[i] = str[idx];
                    str[idx] = c;
                    break;
                }
            }
        }
        
        if (idx == -1) return num;
        return stoi(str);
    }
};
