class Solution {
public:
    int n;
    vector<long long>dp;
    long long helper(vector<vector<int>>& questions,int i)
    {
        if( i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long pick = questions[i][0] + helper(questions,i + questions[i][1] + 1);
        long long not_pick = helper(questions,i+1);
        return dp[i] = max(pick,not_pick);
    }
    long long mostPoints(vector<vector<int>>& questions) 
    {
      n = questions.size();
      dp.assign(n,-1);
      long long ans = helper(questions,0); 
      return ans; 
    }
};