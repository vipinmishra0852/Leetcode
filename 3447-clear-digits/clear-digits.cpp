class Solution {
public:
    string clearDigits(string s) 
    {
    int n = s.length();
    stack<char>st;
    for(int i = 0 ; i  < n ; i++)
    {
      if(s[i] >= 'a' && s[i] <= 'z')st.push(s[i]);
      if(s[i] >= '0' && s[i] <= '9' && !st.empty())st.pop();
    }
    string ans;
    while(!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;    
    }
};