class Solution {
public:
    // int limit;
    // vector<int>calc(int n,vector<int>&ans)
    // {
    //   if(n == limit + 1) return 0;

    //   return calc()
    // }
    vector<int> countBits(int n) 
    {
    // limit = n;
    vector<int>ans(n,0);
    ans.push_back(0);
    for(int i = 1 ; i <= n ; i++)
    {
     ans[i] = __builtin_popcount(i);
    }
    return ans;
    }
};