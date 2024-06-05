class Solution {
public:
    bool isValid(string s)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n = s.size();
  stack<char> st;
  for (int i = 0; i < n; i++)
  {
    if (n == 0 || n % 2 != 0)
    {
      return 0;
    }
    else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
    {
      st.push(s[i]);
    }
    else if (s[i] == ')')
    {
      if (st.size() == 0)
        return false;
      else
      {
        if (st.top() == '(')
        {
          st.pop();
        }
        else
          return false;
      }
    }
    else if (s[i] == ']')
    {
      if (st.size() == 0)
        return false;
      else
      {
        if (st.top() == '[')
        {
          st.pop();
        }
        else
          return false;
      }
    }
    else if (s[i] == '}')
    {
      if (st.size() == 0)
        return false;
      else
      {
        if (st.top() == '{')
        {
          st.pop();
        }
        else
          return false;
      }
    }
  }

  if (st.size() == 0)
    return true;
  else
    return false;
}
};