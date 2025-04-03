class Solution {
public:
    int n,m;
    string s1,s2;
    vector<vector<int>>dp;
    int solve(int i,int j)
    {
        if(i == n)
        {
            return m-j;
        }
        if(j == m)
        {
            return n-i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) 
        {
            return dp[i][j] = solve(i+1,j+1);
        }
        int insert = 1 + solve(i,j+1);
        int del    = 1 + solve(i+1,j);
        int replace = 1 + solve(i+1,j+1);
        return dp[i][j] = min({insert,del,replace});
    }
    
    int minDistance(string word1, string word2) 
    {
     n = word1.size(); 
     m = word2.size();
     dp.resize(n+1,vector<int>(m+1,-1));
     s1 = word1;
     s2 = word2;
     int ans = solve(0,0);
     return ans;
    }
};