class Solution {
public:
    int minimumLength(string s)
    {
      int n = s.length();
      map<char,int>m;
       int ans=0;
      for(int i = 0 ; i<n;i++)
      {
        m[s[i]]++;
      }  
      for(auto &it:m)
      {
        if(it.second >=3)
        {
            if(it.second %2 == 0) {it.second = 2;}
            else {it.second = 1;}
        }
      }
     
      for(auto it:m)
      {
        ans = ans+ it.second;
      }

      return ans;
    }
};