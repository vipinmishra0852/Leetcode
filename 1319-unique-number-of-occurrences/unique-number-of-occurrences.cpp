class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
         map<int,int>m;
         for(int i=0;i<arr.size();i++)
         {
            m[arr[i]]++;
         }
         set<int>s;
         for(auto i:m)
         {
            if(s.find(i.second)!=s.end())
             {
                return false;
             }
            else s.insert(i.second);
         }
         return true;
    }
};