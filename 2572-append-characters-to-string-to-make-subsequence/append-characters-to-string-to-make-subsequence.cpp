class Solution {
public:
    int appendCharacters(string s, string t) 
    {  ios::sync_with_stdio(false);
       cin.tie(NULL);
       int i = 0;
       int u = t.size();
       int v=s.size();
       int j=0;
       int count=0;
       while( j<u )
       {
         if(s[i]==t[j])
         {
           i++;
           j++;
           count++;
           if(i>=v || j>=u) break;
         }
         else
         {
           i++;
           if(i>=v || j>=u) break;
         }
       }
  return t.size()-count;
    }
};