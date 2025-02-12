class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
     map<char,int>m1;
     map<char,int>m2;
     for(auto i:ransomNote)
     {
      m1[i]++;
     }
     for(auto j:magazine)
     {
      m2[j]++;
     }
     for(auto it:m1)
     {
        if(m2.find(it.first) != m2.end())
        {
            int n = m2[it.first];
            if(n < it.second) return false;
        }
        else return false;
     }
     return true;
    }
};