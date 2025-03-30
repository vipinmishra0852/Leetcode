class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
    map<char,int>mp;
    for(int i = 0;i<s.length();i++)
    {
        mp[s[i]] = i;
    }
    vector<int>ans;
    int window = 0;
    int prev = 0;
    for(int i = 0;i<s.length();i++)
    {
        window = max(window,mp[s[i]]);
        if(i == window)
        {
            ans.push_back(i - prev + 1);
            prev = i + 1;
        }
    } 
    return ans;   
    }
};