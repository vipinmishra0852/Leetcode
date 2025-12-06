class Solution {
public:
    int countCollisions(string s) 
    {
        stack<char> st;
        int count = 0;

        for (char ch : s)
        {
            if (st.empty()) 
            {
                st.push(ch);
            }
            else 
            {
                if (ch == 'L') 
                {
                    if (st.top() == 'R') 
                    {
                        count += 2;
                        st.pop();
                        
                        while (!st.empty() && st.top() == 'R') 
                        {
                            count += 1;
                            st.pop();
                        }

                        st.push('S');
                    }
                    else if (st.top() == 'S') 
                    {
                        count += 1;
                    }
                    else 
                    {
                        st.push('L');
                    }
                }
                else if (ch == 'S') 
                {
                    while (!st.empty() && st.top() == 'R') 
                    {
                        count += 1;
                        st.pop();
                    }
                    st.push('S');
                }
                else 
                {
                    st.push('R');
                }
            }
        }
        return count;
    }
};
