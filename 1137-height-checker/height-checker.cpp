class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
    //  ios::sync_with_stdio(false);
    //  cin.tie(NULL);
    //  cout.tie(NULL);
     int n=heights.size();
     vector<int>helper(n,0);
     helper=heights;
     sort(heights.begin(),heights.end());
     int count=0;
     for(int i=0;i<n;i++)
     {
        if(heights[i]!=helper[i])
        {
            count++;
        }
     } 
     return count;  
    }
};