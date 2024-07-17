class Solution {
public:
    int n,m;
    
    void dfs(vector<vector<int>>&image, int currRow, int currCol, int initialcolor,int newcolor)
    {
     if(currRow < 0 || currCol < 0 || currRow >= n || currCol >=m) return;
     if(image[currRow][currCol] != initialcolor) return;
     image[currRow][currCol] = newcolor;
     dfs(image,currRow+1,currCol,initialcolor,newcolor);
     dfs(image,currRow-1,currCol,initialcolor,newcolor);
     dfs(image,currRow,currCol+1,initialcolor,newcolor);
     dfs(image,currRow,currCol-1,initialcolor,newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    { ios::sync_with_stdio(0);
    cin.tie(0);
     if(color == image[sr][sc]) return image;
     n = image.size();
     m = image[0].size();
     dfs(image,sr,sc,image[sr][sc],color);
     return image; 
    }
};