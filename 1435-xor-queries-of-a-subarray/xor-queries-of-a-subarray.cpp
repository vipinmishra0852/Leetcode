class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        int s = arr.size();
        
        // Initialize the prefix XOR array with the size of arr
        vector<int> preXor(s, 0);
        preXor[0] = arr[0];
        
        // Build the prefix XOR array
        for (int i = 1; i < s; i++)
        {
            preXor[i] = preXor[i - 1] ^ arr[i];
        }
        
        int r = queries.size();
        vector<int> res;
        
        // Process each query
        for (int j = 0; j < r; j++)
        {
            int left = queries[j][0];
            int right = queries[j][1];
            
            // XOR from left to right: 
            // If left == 0, the result is just preXor[right]
            if (left == 0) {
                res.push_back(preXor[right]);
            } else {
                // Otherwise, XOR is preXor[right] ^ preXor[left-1]
                res.push_back(preXor[right] ^ preXor[left - 1]);
            }
        }
        
        return res;
    }
};
