class Solution {
public:
    void combination(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                combination(result, current, candidates, target - candidates[i], i + 1);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        combination(result, current, candidates, target, 0);
        return result;
    }
};
