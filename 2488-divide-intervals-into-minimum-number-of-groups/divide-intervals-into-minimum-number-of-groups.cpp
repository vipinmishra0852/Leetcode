class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> startTimes, endTimes;
        
        for (auto& interval : intervals) {
            startTimes.push_back(interval[0]);
            endTimes.push_back(interval[1]);
        }
        
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        int maxGroups = 0;
        int currentGroups = 0;
        int i = 0, j = 0;
        int n = intervals.size();
        
        while (i < n && j < n) {
            if (startTimes[i] <= endTimes[j]) {
                currentGroups++;
                maxGroups = max(maxGroups, currentGroups);
                i++;
            } else {
                currentGroups--;
                j++;
            }
        }
        
        return maxGroups;
    }
};
