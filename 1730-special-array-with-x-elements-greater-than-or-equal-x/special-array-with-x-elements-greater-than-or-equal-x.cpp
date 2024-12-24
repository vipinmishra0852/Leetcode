class Solution {
public:
    int func(vector<int>& arr, int find) {
        int cnt = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] >= find) cnt++;
        }
        return cnt;
    }

    int specialArray(vector<int>& arr) {
        int maxi = INT_MIN;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }

        for (int i = 1; i <= maxi; i++) { // Changed range to include `maxi`
            if (func(arr, i) == i) {
                return i;
            }
        }

        return -1;
    }
};
