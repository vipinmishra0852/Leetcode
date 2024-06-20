class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
     int row = matrix.size();
     int column = matrix[0].size();
     vector<int>me;
     for(int i=0;i<row;i++)
     {
        for(int j=0;j<column;j++)
        {
         me.push_back(matrix[i][j]);
        }
     }   
     sort(me.begin(),me.end());
     return me[k-1];
    }
};