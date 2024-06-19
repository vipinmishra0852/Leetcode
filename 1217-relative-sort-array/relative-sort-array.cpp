class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        map<int,int>m;
        for(int i=0;i<arr1.size();i++)  
        {
            m[arr1[i]]++;
        }
        vector<int>v;
        int i=0;
        for(int i=0;i<arr2.size();i++)
        {
         if(m.find(arr2[i])!=m.end())
         {
            int n = m[arr2[i]];
            for(int j=0;j<n;j++)
            {
                v.push_back(arr2[i]);
            }
            m[arr2[i]]=0;
         }

        }
        vector<int>rem;
        for(auto ele:m)
        {
            if(ele.second > 0)
            { int x = ele.second;
            for(int k=0;k<x;k++)
            {
           rem.push_back(ele.first);
            }
            ele.second = 0;
            }
        }
        sort(rem.begin(),rem.end());
        for(int t:rem)
        {
            v.push_back(t);
        }
        return v;
    }
};