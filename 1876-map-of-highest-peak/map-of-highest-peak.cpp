class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
    int n = isWater.size();
    int m = isWater[0].size();
    vector<vector<int>>height(n,(vector<int>(m,-1)));
    queue<pair<int,int>>q;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(isWater[i][j] == 1)
            {
                height[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    vector<vector<int>>directions = {{1,0},{-1,0},{0,-1},{0,1}};
    while(!q.empty())
    {
        auto [r,c] = q.front();
        q.pop();
        for(auto dir:directions)
        {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && height[nr][nc] == -1)
            {
            height[nr][nc] = height[r][c] + 1;
            q.push({nr,nc});
            }
        }
    }
    return height;    
    }
};