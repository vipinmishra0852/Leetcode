class Solution {
public:
    int maximumLength(string s) 
    {
    int n = s.length();
    vector<vector<int>>v(26,vector<int>(n+1,0));   
    char prev = s[0];
    int len = 0;
    for(int i=0;i<n;i++)
    {   
     char curr = s[i];
     if(curr == prev)
     {
       len++;
       v[curr - 'a'][len]++;
     }
     else
     {    len = 1;
       v[curr - 'a'][len]++;
        
    prev = curr;
     }
    }
    int result = 0;
    for(int i = 0 ; i< 26;i++)
    {
     int cumSum = 0;
     for(int j = n;j>=1;j--)
     {
     cumSum+=v[i][j];
     if(cumSum >= 3)
     {
        result = max(result,j);
        break;
     }
     }
    }
    return (result == 0)? -1:result;
   
    }
};