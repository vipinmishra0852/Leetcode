class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequencyMap;
        
        
        for (const string& str : arr) {
            frequencyMap[str]++;
        }

      
        for (const string& str : arr) {
            if (frequencyMap[str] == 1) {
                k--;
                if (k == 0) {
                    return str;
                }
            }
        }
        
        return ""; 
    }
};