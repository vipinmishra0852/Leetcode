class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
    int n = s.length();
    set<char>st;
    int i = 0;
    int j = 0;
    int len = 0;
    while(j < n )
    {
     if( st.find(s[j]) == st.end())
     {
        st.insert(s[j]);
        j++;
        len = max(len,j-i);
     }
     else
     {
       while(!st.empty() && st.count(s[j]))
       {
     st.erase(s[i]);
     i++;
       } 
     }
    }  
     return len;  
    }
};