class Solution {
public:
    int n,m;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
    n = mat.size();
    m = mat[0].size();
    vector<vector<int>>result(n,vector<int>(m,-1)); 
    queue<pair<int,int>>q;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j< m ; j++)
        {
            if(mat[i][j] == 0) 
            {
                result[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    vector<vector<int>>directions({{1,0},{-1,0},{0,-1},{0,1}});
    while(!q.empty())
    {
        pair<int,int>p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        for(int d = 0 ; d < 4 ; d++)
        {
         int nr = i + directions[d][0];
         int nc = j + directions[d][1];
         if(nr >= 0 && nr < n && nc >= 0 && nc < m && result[nr][nc] == -1 )
         {
         result[nr][nc] = result[i][j] + 1;
         q.push({nr,nc});
         }
        }
    }
    return result;
    }
};