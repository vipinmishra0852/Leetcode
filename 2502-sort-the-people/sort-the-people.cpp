class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
    int n = names.size();
     map<int,string>m;
     for(int i = 0 ; i < n ; i++)
     {
        m[heights[i]] = names[i];
     }
     vector<string>result;
     for( auto i: m)
     {
        result.push_back(i.second);
     }
     reverse(result.begin(),result.end());
     return result;
    }
};