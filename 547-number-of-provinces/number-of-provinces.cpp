class Solution {
public:
    int n;
    void dfs(map<int,vector<int>>&v,int i,vector<bool>&visited)
    {
        visited[i] = true;
        for(auto u:v[i])
        if(!visited[u])
        {
            dfs(v,u,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
     n = isConnected.size();
    map<int,vector<int>>v;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j<isConnected[0].size();j++)
        {
            if(isConnected[i][j] == 1)
            {
            v[i].push_back(j);
            v[j].push_back(i);
            }
        }
    }
    int count = 0;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(v,i,visited);
            count++;
        }
    }
    return count;
    }
};