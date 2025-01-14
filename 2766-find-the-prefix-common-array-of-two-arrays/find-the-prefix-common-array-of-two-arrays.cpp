class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
    int n = A.size();
    vector<int>ans;
    vector<int>freq(2*n + 1,0);
    int count = 0;
    for(int i = 0 ; i<n;i++)
    {   
        freq[A[i]]++;
        freq[B[i]]++;
        if(freq[A[i]] == 2) count++;
        if(freq[B[i]] == 2) count++;
        if(A[i] == B[i]) count = count - 1;
        ans.push_back(count);
    }
    return ans;
    }
};