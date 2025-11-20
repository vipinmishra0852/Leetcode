class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>adj,vector<bool>&visited)
    {
        visited[node] = true;
        for(int child:adj[node])
        {
            if(!visited[child])
            {
                dfs(child,adj,visited);
            }
        }
        return;

    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
    int count = 0;
    unordered_map<int,vector<int>>adj;
    int n = isConnected.size();
    for(int i = 0 ; i < n ; i++)
    {   
        vector<int>temp =  isConnected[i];
        int size =temp.size();
        for(int j = 0 ; j < size ; j++)
        {
            if(temp[j] == 1 && i != j)
            adj[i].push_back(j);
        }
    }
    vector<bool>visited(n+1,false);
    for(int i = 0 ; i <n ; i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited);
            count++;
        }
    }
    return count;    
    }
};