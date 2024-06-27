bool cmp(vector<int>&a,vector<int>&b)
{
  return a[0]<b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int count = 1;
        vector<int>ele(2,0);
        ele[0] = points[0][0];
        ele[1] = points[0][1];
   
        int i = 1;
       while(i < points.size() )
        {   
            vector<int>curr = points[i];
            if(ele[1] >= curr[0] )
            {    
    
                ele[0] = max(curr[0],ele[0]);
                ele[1] = min(curr[1],ele[1]);

            }
            else
            {
             count++;
           
             ele[0] = curr[0];
             ele[1] = curr[1];
            
            
            }
           i++; 
        }
        return count;
    }
};