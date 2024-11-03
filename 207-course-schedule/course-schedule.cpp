class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
    int v = numCourses;
    vector<vector<int>>graph(numCourses);    
    vector<int>indegree(v,0);
    for(auto pre:prerequisites)
    {
   int a = pre[0];
   int b = pre[1];
   graph[b].push_back(a);
   indegree[a]++;
    }

    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i] == 0)
        { 
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        count++;
        
        for(auto neighbour:graph[n])
        {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                   
                }
         }

    }
    
    if(count == v) return true;
    
    return false;
}
    
};