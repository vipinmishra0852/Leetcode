class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
     int n  = stones.size();
     priority_queue<int>pq;
     for(int ele: stones)
     {
      pq.push(ele);
     }   
     while(pq.size()>1)
     {
        int ele1 = pq.top();
        pq.pop();
        int ele2 = pq.top();
        pq.pop();
        pq.push(ele1 - ele2);
     }
     return pq.top();
         }
};