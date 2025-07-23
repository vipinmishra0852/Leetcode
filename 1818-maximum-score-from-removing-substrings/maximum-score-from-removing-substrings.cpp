class Solution {
public:
    int removeab(string &s)
    {
       stack<char>st;
       int sz = s.length();
       int m = 0;
       for(int i = 0 ; i < sz ; i++)
        {
            char ch = s[i];
            if(st.size() == 0) st.push(ch);
            else 
            {
                char check = st.top();
                string temp = "";
                temp+=check;
                temp+=s[i];
                if(temp == "ab")
                {
                     m++;
                     st.pop();
                }
                else st.push(s[i]);
        }

    }
    string temp = "";
    while(!st.empty())
    {
        
        temp+=st.top();
        st.pop();
    }
    reverse(temp.begin(),temp.end());
    s = temp;
    return m;
    } 
    int removeba(string &s)
    {
        stack<char>st;
       int sz = s.length();
       int m = 0;
       for(int i = 0 ; i < sz ; i++)
        {
            char ch = s[i];
            if(st.size() == 0) st.push(ch);
            else 
            {
                char check = st.top();
                string temp = "";
                temp+=check;
                temp+=s[i];
                if(temp == "ba")
                {
                     m++;
                     st.pop();
                }
                else st.push(s[i]);
        }

    }
     string temp = "";
    while(!st.empty())
    {
        
        temp+=st.top();
        st.pop();
    }
    reverse(temp.begin(),temp.end());
    s = temp;
    return m;
    }
    int maximumGain(string s, int x, int y) {
       int m = 0;
       int n = 0;
       
        
        if(x > y) {
             m = removeab(s);
             n = removeba(s);
        }
        else
        {
            n = removeba(s);
            m = removeab(s);
        }
        
          int ans = m*x + n * y;
        return ans;
             
            
        }
};