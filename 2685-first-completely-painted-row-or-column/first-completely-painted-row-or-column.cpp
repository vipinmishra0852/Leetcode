class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
     int row = mat.size();
     int col = mat[0].size();
     map<int,pair<int,int>>m;
     for(int i = 0; i < row ; i++)
     {
        for(int j = 0 ; j < col ; j++)
        {
            int ele = mat[i][j];
            pair<int,int>p;
            p.first = i;
            p.second = j;
            m[ele] = p;
        }
     }
     vector<int>rowArr(row,0);
     vector<int>colArr(col,0);
     for(int i = 0 ; i < arr.size() ; i++)
     {
       pair<int,int>temp;
       temp = m[arr[i]];
       int s = temp.first;
       int q = temp.second;
       rowArr[s]++;
       colArr[q]++;
       if(rowArr[s] == col || colArr[q] == row)
       {
        return i;
       }
     }
     return -1;
    }
};