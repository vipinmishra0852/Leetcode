class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
     int n = nums.size();
     map<int,int>mp;
     for(int i=0;i<n;i++)
     {
        mp[nums[i]]++;
     }   
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    for(auto x : mp)
    {
        int ele = x.first;
        int freq = x.second;
        pair<int,int> p = {freq,ele};
        pq.push(p);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    vector<int>ans;
    while(pq.size()>0)
    {
        pair<int,int> temp = pq.top();
        int a = temp.second;
        ans.push_back(a);
        pq.pop();
    }
    return ans;
    }
};