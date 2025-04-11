class Solution {
public:
    bool check(int n)
    {
        string s = "";
        s = to_string(n);
        if( s.length()% 2 != 0) return false;
        int j = s.length()/2;
        int n1 = 0;
        int n2 = 0;
        for(int i = 0 ; i < s.length();i++)
        {
          if(i < j){
          n1 = n1 + s[i] - '0';
          }
          else
          {
            n2 = n2 + s[i]-'0';
          }
        }
    return (n1 == n2);
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
       for(int i = low ; i <= high; i++)
       {
        if(check(i))
        {
            count++;
        }
        else continue;
       } 
       return count;
    }
};