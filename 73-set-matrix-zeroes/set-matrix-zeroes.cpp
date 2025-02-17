class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) 
    {
    set<int>s1;
    set<int>s2;
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(matrix[i][j] == 0) {
                s1.insert(i);
                s2.insert(j);
            }
        }
    }
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0; j < col ; j++)
        {
            if( s1.find(i) != s1.end() || s2.find(j) != s2.end() ) matrix[i][j] = 0;
        }
    }
    
    }
};