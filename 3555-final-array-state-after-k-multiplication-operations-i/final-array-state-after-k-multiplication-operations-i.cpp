class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
    int m = multiplier;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
    for(int i = 0;i<nums.size();i++)
    {
      min_heap.push({nums[i],i});
    }
    while(k)
    {
        pair<int,int>p = min_heap.top();
        int ele = p.first;
        int idx = p.second;
        min_heap.pop();
        ele = ele*m;
        nums[idx] = ele;
        min_heap.push({ele,idx});
        k--;
    }
    
    return nums;
    }
};