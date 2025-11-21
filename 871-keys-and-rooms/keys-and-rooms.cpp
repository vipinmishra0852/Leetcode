class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
    unordered_map<int,vector<int>>adj;
    int n = rooms.size();
    for(int i = 0 ; i <  n ; i++)
    {
        for(int key:rooms[i])
        {
            adj[i].push_back(key);
        }
    }
    set<int>visited;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int temp = q.front();
        visited.insert(temp);
        q.pop();
        for(int child:adj[temp])
        {
            if(visited.find(child) == visited.end())
            {
                q.push(child);

            }   
        }
    }
    if(visited.size() == n) return true;
    return false;   
    }
};