class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
    int n=A.size();
    map<int,int>m1;
    map<int,int>m2;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        m1[A[i]]++;
        m2[B[i]]++;
        int count = 0;
        for(auto it:m1)
        {
            if(m2.find(it.first) != m2.end())
            {
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
    }
};