class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    { ios::sync_with_stdio(false);
    cin.tie(NULL);
     priority_queue<int,vector<int>,greater<int>>pq;
     int n = nums.size();
     for(int i = 0;i<n;i++)
     {
        pq.push(nums[i]);
     }
    while(k>0)
    {
        int t = pq.top();
        if(t == 0) break;
        pq.pop();
        t = -t;
        pq.push(t);
        k--;
    }
    int sum = 0;
    while(pq.size() > 0)
    {
      sum = sum + pq.top();
      pq.pop();  
    }
    return sum;
    }
};