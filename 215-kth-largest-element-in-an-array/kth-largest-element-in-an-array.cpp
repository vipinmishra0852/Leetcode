#include <vector>
using namespace std;

class Solution {
public:
    // Function to swap two elements
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Partition function for Quickselect
    int partition(vector<int> &arr, int low, int high) {
        int pivot = arr[high];
        int i = low;

        for (int j = low; j < high; ++j) {
            if (arr[j] > pivot) { // Note the comparison here for kth largest
                swap(arr[i], arr[j]);
                ++i;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    // Quickselect function
    int quickSelect(vector<int> &arr, int low, int high, int k) {
        if (low <= high) {
            int pi = partition(arr, low, high);

            if (pi == k) {
                return arr[pi];
            } else if (pi < k) {
                return quickSelect(arr, pi + 1, high, k);
            } else {
                return quickSelect(arr, low, pi - 1, k);
            }
        }
        return -1; // This should never be reached if k is valid
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, k - 1);
    }
};
