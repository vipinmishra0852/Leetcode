class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
    int n = allowed.size();
    int m = words.size();
    map<char,bool>mp;
    for(int i=0;i<n;i++)
    {
        mp[allowed[i]]=true;
    }
    int count=0;
    for(int j = 0 ; j < m;j++)
    {
        string s = words[j];
        int k = s.size();
        for(int t = 0;t<k;t++ )
        {
            if(mp.find( s[t] ) == mp.end())
            {
             count++;
             break;
            } 
        }
    }
    return m-count;
    }
};