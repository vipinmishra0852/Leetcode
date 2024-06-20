class Solution {
public:
typedef pair<int,int>pp;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {

      priority_queue<pp>pq;
      int n= arr.size();
      for(int i=0;i<n;i++)
      {
        int ele = arr[i];
        int diff = abs(x-arr[i]);
        pair<int,int>temp = {diff,ele};
       pq.push(temp);
        if(pq.size()>k)
        {
            pq.pop();
             
        }
      }
      vector<int>ans;
      while(pq.size()>0)
      {
        int ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();   
      }
      sort(ans.begin(),ans.end());
    return ans;
    }
};