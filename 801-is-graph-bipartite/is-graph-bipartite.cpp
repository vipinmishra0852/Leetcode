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
    bool isBipartite(vector<vector<int>>& graph) 
    {
     int n = graph.size();
     vector<int>color(n,-1);

     for(int i = 0 ; i < n ; i++)
     {
        if(color[i] == -1)
        {
            if(!dfs(i,graph,color,1)) return false;
        }
     }
     return true;    
    }
};