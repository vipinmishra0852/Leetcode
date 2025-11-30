class Solution {
public:
    bool dfs(int curr,vector<vector<int>>& graph,vector<int>&color,int currcolor)
    {
        color[curr] = currcolor;
        for(int child:graph[curr])
        {
            if(color[child] == color[curr]) return false;
            if(color[child] == -1)
            {
                if(!dfs(child,graph,color,1-currcolor)) return false;
            }
        }
        return true;
    }
    bool bfs(int curr,vector<vector<int>>& graph,vector<int>&color,int currcolor)
    {
        queue<int>q;
        q.push(curr);
        color[curr] = currcolor;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int child:graph[node])
            {
                if(color[child] == color[node]) return false;
                if(color[child] == -1) {
                    q.push(child);
                    color[child] = 1 - color[node];
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
     int n = graph.size();
     vector<int>color(n,-1);

     for(int i = 0 ; i < n ; i++)
     {
        if(color[i] == -1)
        {
            if(!bfs(i,graph,color,1)) return false;
        }
     }
     return true;    
    }
};