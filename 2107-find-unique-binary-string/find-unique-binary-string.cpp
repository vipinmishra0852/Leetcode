class Solution {
public:
    string findDifferentBinaryString(vector<string>& v) 
    {
          string s="";
          for(int i=0;i<v.size();++i)
            if(v[i][i]=='0')s+='1';else s+='0';
          return s;
    }
};