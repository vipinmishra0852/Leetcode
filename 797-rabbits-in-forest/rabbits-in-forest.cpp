class Solution {
public:
    int numRabbits(vector<int>& arr) {
     int n = arr.size();
     map<int,int>m;
     for(int i = 0;i<n;i++)
     {
        m[arr[i]]++;
     }
     int ans = 0;
     for(auto i:m)
     {  
        if(i.first == 0)
        {
          ans=ans + i.second;
        }
        else if( i.second - i.first <=1 )
        {
            ans = ans + i.first + 1;
        }
        else if ( (i.second) % (i.first + 1) == 0 )
        {
             int prod = (i.second) / (i.first + 1) ;
            ans = ans + prod * (i.first + 1);
        }
        else 
        {   int rem = (i.second) % (i.first + 1);
            int prod = (i.second) / (i.first + 1) ;
            ans = ans + prod * (i.first + 1) + i.first + 1;
        }
     }
     return ans;
    }
};