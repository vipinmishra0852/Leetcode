class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = -1;
        int maxArea = -1;
        
        for (auto &rect : dimensions) {
            int len = rect[0];
            int wid = rect[1];
            
            int diagSq = len * len + wid * wid;
            int area = len * wid;
            
            if (diagSq > maxDiagonal) {
                maxDiagonal = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagonal) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
