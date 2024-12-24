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
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxi = arr[n - 1];  // Corrected this line, max is the last element after sorting

        int low = 1;
        int high = maxi;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int special = func(arr, mid);

            if (special == mid) {
                ans = mid;
                break;
            } else if (special > mid) {
                low = mid + 1;  // Corrected case: low was in lowercase
            } else {
                high = mid - 1;  // Corrected case: high was in lowercase
            }
        }
        return ans;
    }
};
