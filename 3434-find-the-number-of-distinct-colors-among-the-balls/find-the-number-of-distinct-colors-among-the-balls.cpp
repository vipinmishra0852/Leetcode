class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
   vector<int> res;
        unordered_map<int, int> balls;
        unordered_map<int, int> colors;
        int distinct = 0;

        for (const auto& q : queries) {
            int b = q[0], c = q[1];
            if (balls.find(b) != balls.end()) {
                int prevColor = balls[b];
                if (prevColor != c) {
                    colors[prevColor]--;
                    if (colors[prevColor] == 0) {
                        distinct--;
                    }
                    colors[c]++;
                    if (colors[c] == 1) {
                        distinct++;
                    }
                    balls[b] = c;
                }
            } else {
                balls[b] = c;
                if (colors[c] == 0) {
                    distinct++;
                }
                colors[c]++;
            }
            res.push_back(distinct);
        }

        return res;
    }
};