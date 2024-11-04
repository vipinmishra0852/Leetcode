class Solution {
public:
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
    int v = numCourses;
    vector<vector<int>>graph;
    graph.resize(v,vector<int>());
    vector<int>indegree(v,0);
    
     for(auto pre:prerequisites)
     {
        int a = pre[0];
        int b = pre[1];
        graph[b].push_back(a);
        indegree[a]++;
     
    }
    queue<int>q;
    for(int i = 0; i < v ;i++)
    {
        if(indegree[i] == 0 )
        {
         q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty())
    {
        int t = q.front();
        ans.push_back(t);
      
        q.pop();
        for(auto neighbour:graph[t])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
      vector<int>d;
      if(ans.size() != v) return d;
      return ans;  
    }
};