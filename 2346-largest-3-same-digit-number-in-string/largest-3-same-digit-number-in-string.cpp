class Solution {
public:
    string largestGoodInteger(string num) 
    {
    int n = num.size();
    char s='a';
    for(int i = 0; i <= n-3 ; i++)
    {
      
      if(num[i] == num[i+1] && num[i+1] == num[i+2] && s=='a')
      {
       s = num[i];
      }
      else if(num[i] == num[i+1] && num[i+1] == num[i+2] && s!='a')
      {
        if(num[i] -'0' > s - '0') s = num[i];
        else continue;
      }
    }
    if(s == 'a') return "";
    string ans(3,s);
    
    return ans;    
    }
};