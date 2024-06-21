class Solution {
public:
    typedef pair<int,int>pp;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     priority_queue< pair < int , pair<int,int> > >pq;
     int row = points.size();
     int column = points[0].size();
    for(int i = 0;i<row;i++)
     {  
       int t = points[i][0];
       int s = points[i][1]; 
        pair<int,int> p = {t,s};
        int a = p.first;
        int b = p.second ;
        int w = pow(a,2);
        int u = pow(b,2);
        int d = w + u;
        pq.push({d,{a,b}});
        if(pq.size()>k)
        {
            pq.pop();
        }
     
     }
     vector<vector<int>>ans;
   
     while(pq.size()>0)
     {  pair<int,int>temp = pq.top().second;
        int x = temp.first;
        int y = temp.second;
        ans.push_back({x,y});
        pq.pop();
     }   
     return ans;
    }
};