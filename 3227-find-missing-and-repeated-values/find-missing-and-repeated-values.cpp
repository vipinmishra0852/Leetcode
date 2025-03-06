class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int>ans;
    map<int,int>mp;
    for(int i = 0 ; i < grid.size();i++)
    {
        for(int j = 0 ; j < grid.size();j++)
        {
         mp[grid[i][j]]++;
        }
    }
    for(auto it:mp)
    {
        if(it.second == 2) 
        {
            ans.push_back(it.first);
        }
    }
    int n = grid.size();
    for(int i = 1;i <= n*n ;i++)
    {
        if(mp.find(i) == mp.end())
        {
            ans.push_back(i);
        }
    } 
    return ans;   
    }
};