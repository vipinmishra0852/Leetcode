class Solution {
public:
    using p = pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto vec:times)
    {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];
        adj[u].push_back({v,w});
    }    
    priority_queue<p,vector<p>,greater<p>>pq;
    vector<int>result(n+1,INT_MAX);
    result[k] = 0;
    pq.push({0,k});
    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
         pq.pop();
        if(d > result[node]) continue;
       
        for(auto &it:adj[node])
        {
        int adjNode = it.first;
        int dist = it.second;
        
        if(d + dist < result[adjNode])
        {
            result[adjNode] = d + dist;
            pq.push({d + dist,adjNode});
        }
        }
    }
    int ans = 0;
        for(int i = 1 ; i <= n;i++) 
        {
            if(result[i] == INT_MAX) return -1;
            ans = max(ans,result[i]);
        }
        return ans; 
    }
};