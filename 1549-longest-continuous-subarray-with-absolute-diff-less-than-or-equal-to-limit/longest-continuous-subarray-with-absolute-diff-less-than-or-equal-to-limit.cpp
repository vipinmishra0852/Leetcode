class Solution {
public:
    typedef pair<int,int>pp;
    int longestSubarray(vector<int>& nums, int limit)
    {
      int n = nums.size();
      priority_queue<pp,vector<pp>>maxpq;
      priority_queue<pp,vector<pp>,greater<pp>>minpq;
      int i = 0;
      int j = 0;
      int maxlength = 0;
      while(j<n)
      {
        maxpq.push({nums[j],j});
        minpq.push({nums[j],j});
        while(maxpq.top().first - minpq.top().first > limit)
        {
            i = (min(maxpq.top().second , minpq.top().second))+ 1;
            while(maxpq.top().second < i)
            {
                maxpq.pop();
            }
                while(minpq.top().second < i)
            {
                minpq.pop();
            }
        }
        maxlength = max(maxlength , j - i + 1);
        j++;
      }
    return maxlength;
    }
};