class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
    queue<int>q;
    unordered_set<int>visited;
    q.push(0);
    visited.insert(0);
    while(!q.empty())
    {
     int curr = q.front();
     q.pop();
     for(int neighbour:rooms[curr])
     {
        if(!visited.count(neighbour))
        {
            q.push(neighbour);
            visited.insert(neighbour);
        }
     }
    }
    return visited.size() == rooms.size();    
    }
};