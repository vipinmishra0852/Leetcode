class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
    map<char,int>m1;
    map<char,int>m2;
    int n1 = s1.length();
    int n2 = s2.length();
    for(int i = 0;i<n1;i++)
    {
      m1[s1[i]]++;  
    } 
     for(int i = 0;i<n2;i++)
    {
      m2[s2[i]]++;  
    }
    int count = 0;
    for(int i = 0 ; i < s1.length() ; i++)
    {
        if(s1[i] != s2[i]) count++;
    } 
    if(count > 2) return false;  
    return m1 == m2; 
    }
};