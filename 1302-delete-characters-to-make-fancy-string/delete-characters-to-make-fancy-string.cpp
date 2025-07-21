class Solution {
public:
    string makeFancyString(string s) {
    int n = s.length();
    int len = 0;
    vector<bool>mark(n,0);
    for(int i = 1 ; i < n ; i++)
    {
        if(s[i-1] == s[i])
        {
            len++;
            if(len >= 2) 
            {
                mark[i] = true;
                
            }
        }
        else len = 0;
    }
    
    string ans = "";
    for(int i = 0 ; i < n ; i++)
    {
        if(mark[i] == true) continue;
        else ans+=s[i];
    }
    cout<<"S   : "<<s<<endl;
    cout<<"ans : "<<ans<<endl;
    return ans;
    }
};