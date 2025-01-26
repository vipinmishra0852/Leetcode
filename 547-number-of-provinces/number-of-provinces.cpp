class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int u)
    {
        visited[u] = true;
        for(auto v:adj[u])
        {
            if(!visited[v]) dfs(adj,visited,v);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
    int n = isConnected.size();
    vector<vector<int>>adj(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(isConnected[i][j]) adj[i].push_back(j);
        }
    }
    vector<bool>visited(n,false);
    int count = 0;
    for(int i = 0 ;i < n ; i++)
    {
     if(!visited[i]) 
     {
        dfs(adj,visited,i);
        count++;
     }
    }
    return count;    
    }
};