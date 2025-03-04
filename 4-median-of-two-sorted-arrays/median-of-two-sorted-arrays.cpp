class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
     int m = nums1.size();
     int n = nums2.size();
     vector<int>temp;
     for(int i=0;i<m;i++)
     {
        temp.push_back(nums1[i]);
     }

     for(int i=0;i<n;i++)
     {
        temp.push_back(nums2[i]);
     }
     sort(temp.begin(),temp.end());
     int s = temp.size();
     double ans = 0;
     if(s%2 != 0)
     {
     ans = double(temp[s/2]);
     cout<<ans;
     }
     else
     {  int t = s/2;
        ans =double( temp[t-1] + temp[t] ) / 2.0;
        cout<<ans;
     }
     return ans;

    }
};