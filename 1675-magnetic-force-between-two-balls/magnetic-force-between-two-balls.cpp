
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // Sort the positions
        sort(position.begin(), position.end());
        
        int n = position.size();
        int left = 1;  // minimum possible distance
        int right = position[n-1] - position[0];  // maximum possible distance
        int answer = 0;
        
        // Binary search on the answer
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceBalls(position, m, mid)) {
                answer = mid;  // update answer
                left = mid + 1;  // try for a larger minimum distance
            } else {
                right = mid - 1;  // try for a smaller minimum distance
            }
        }
        
        return answer;
    }
    
    bool canPlaceBalls(const vector<int>& position, int m, int minDist) {
        int count = 1;  // place the first ball at the first position
        int lastPos = position[0];
        
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minDist) {
                count++;
                lastPos = position[i];
                if (count == m) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
