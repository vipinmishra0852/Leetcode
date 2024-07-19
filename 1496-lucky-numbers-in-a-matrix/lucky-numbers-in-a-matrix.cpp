class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
    int n = matrix.size();
    int m = matrix[0].size();
    map<int,int>mp;
    for(int i = 0 ; i < n;i++)
    {   int x = INT_MAX;
        for(int j = 0 ; j < m;j++)
        {
            x = min(matrix[i][j],x ); 
        }
        mp[x]++;
    }
    for(int j = 0 ; j < m ; j++)
    {   
        int y = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
         y = max(y,matrix[i][j]);
        }
        mp[y]++;
    }
    vector<int>ans;
    for(auto i:mp)
    {
        if(i.second == 2)
        {
         ans.push_back(i.first);
         break;
        }
    }
    return ans;
    }
};