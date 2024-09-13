class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) 
    {
    int r = q.size();
    int c = q[0].size();
    int s = arr.size();
    vector<int>ans;
    for(int i=0;i<r;i++)
    {
        vector<int>temp(2,0);
        temp[0] = q[i][0];
        temp[1] = q[i][1];
        int res=0;
        for(int j=temp[0];j<=temp[1];j++)
        {
         res=res^arr[j];
        }
        ans.push_back(res);
    }  
    return ans;   
    }
};