bool compare(vector<int>& p1, vector<int>& p2) {
    if (p1[0] == p2[0]) {
        return p1[1] > p2[1];
    }
    return p1[0] < p2[0];
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), compare);

        int count = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int bestY = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if (y2 <= y1 && y2 > bestY) {
                    count++;
                    bestY = y2;
                }
            }
        }
        return count;
    }
};
