class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        // Map to store element positions
        map<int, pair<int, int>> m;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                m[mat[i][j]] = {i, j}; // Map each element to its position
            }
        }

        // Arrays to track row and column completions
        vector<int> rowArr(row, 0);
        vector<int> colArr(col, 0);

        // Process the elements in the order of `arr`
        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = m[arr[i]]; // Get the row and column of the element
            rowArr[r]++;
            colArr[c]++;
            
            // Check if the row or column is completely filled
            if (rowArr[r] == col || colArr[c] == row) {
                return i;
            }
        }

        return -1; // If no row or column is completely filled
    }
};
