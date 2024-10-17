class Solution {
public:
    vector<int> v;

    // Function to manually sort the vector in descending order using Bubble Sort
    void manualSort() {
        int n = v.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                // Compare adjacent elements and swap if they are in the wrong order
                if (v[j] < v[j + 1]) {
                    swap(v[j], v[j + 1]);
                }
            }
        }
    }

    void digits(int x) {
        while (x > 0) {
            int d = x % 10;
            x = x / 10;
            v.push_back(d);
        }
        // Call the custom sort function
        manualSort();
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
