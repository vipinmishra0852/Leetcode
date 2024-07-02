class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<int,int>m1;
    for(int ele:nums1)
    {
        m1[ele]++;
    }
    map<int,int>m2;
    for(int ele :nums2)
    {
        m2[ele]++;
    }
    vector<int>ans;
    for(auto i:m1)
    {
        if(m2.find(i.first)!=m2.end())
        {   int m = min(i.second,m2[i.first]);
           for(int k=0;k<m;k++)
           {
            ans.push_back(i.first);
           }
        }
    }
    return ans;
    }
};