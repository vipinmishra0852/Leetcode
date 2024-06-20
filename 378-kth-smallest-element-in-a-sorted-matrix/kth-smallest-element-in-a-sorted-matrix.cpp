class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
     int row = matrix.size();
     int column = matrix[0].size();
     int n = row*column;
     vector<int>me;
     priority_queue<int,vector<int>,greater<int>>pq;
     for(int i=0;i<row;i++)
     {
        for(int j=0;j<column;j++)
        {if(pq.size()>n-k)
        {
            pq.pop();
           
        }
          pq.push(matrix[i][j]);
        }
     }   
    
     return pq.top();
    }
};