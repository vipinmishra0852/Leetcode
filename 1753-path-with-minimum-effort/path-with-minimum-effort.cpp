class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    
    int m,n;
    bool isSafe(int x,int y,int m,int n)
    {
        if(x >= m || x < 0 || y >= n || y < 0) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
     m = heights.size();
     n = heights[0].size();

    vector<vector<int>>result(m,vector<int>(n,INT_MAX));
    priority_queue<p,vector<p>,greater<p>>pq;
    result[0][0] = 0;
    pq.push({0,{0,0}}); 
    while(!pq.empty())
    {
        int diff = pq.top().first;
        auto coord = pq.top().second;
        pq.pop();
        int x = coord.first;
        int y = coord.second;

        for(auto &dir:directions)
        {
         int x_ = x + dir[0];
         int y_ = y + dir[1];

         if(isSafe(x_,y_,m,n))
         {
          int absDiff = abs(heights[x_][y_] - heights[x][y]);
          int maxDiff = max(diff,absDiff);
          if(result[x_][y_] > maxDiff)
          {
            result[x_][y_] = maxDiff;
            pq.push({maxDiff,{x_,y_}});
          }
         }
        }
    }
    return result[m-1][n-1];
    }
};