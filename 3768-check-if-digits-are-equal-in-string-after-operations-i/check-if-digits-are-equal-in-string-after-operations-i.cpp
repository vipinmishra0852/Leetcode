class Solution {
public:
    bool hasSameDigits(string s) {
     int len = s.length();
     while(len > 2)
     {
        string temp="";
        for(int i = 1 ; i < len ; i++)
        {
         char digit = ((s[i-1]-'0')+(s[i]-'0'))%10;
         temp+=digit;
        }
        s = temp;
        len = s.length();
     }
     if(s[0] == s[1]) return true;
     return false;   
    }
};