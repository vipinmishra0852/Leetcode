class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
     unordered_map<int,int>m;
     for(auto ele:arr)
     {
       ele = ((ele % k) + k) % k;
       m[ele]++;
     }   
     if(m.find(0)!=m.end())
     {
        if(m[0]%2!=0) return false;
        m.erase(0);
     }
     for(auto i:m)
     {
        int ele = i.first;
        int rem = k - ele;
        if(m.find(rem)==m.end()) return false;
        if(m[ele]!=m[rem]) return false;

     }
     return true;
    }
};