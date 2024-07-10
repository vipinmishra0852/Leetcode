class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
    stack<string>st;
    int n = logs.size();
    int i = 0;
    for(int i = 0; i<n ;i++)
    {
    if(logs[i] == "../")
    {
        if(st.size() == 0) continue;
        else st.pop();
    }
    else if(logs[i] == "./") continue;
    else
    {
        st.push(logs[i]);
    }
    
    }
    int ans = 0;
    while(!st.empty())
    {
        st.pop();
        ans++;
    }
    return ans;
    }
};