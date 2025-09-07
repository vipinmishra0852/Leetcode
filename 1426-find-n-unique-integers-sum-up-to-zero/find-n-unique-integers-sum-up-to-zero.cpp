class Solution {
public:
    vector<int> sumZero(int n) 
    {
    vector<int>v;
    vector<int>temp;
    v.push_back(0);
    if(n == 1) return v;
    else
    {
    if(n%2  != 0 )
    {
        for(int i = -n/2;i<= n/2 ; i++)
        {
            if(i == 0) continue;
            else v.push_back(i);
        }
        return v;
    }
    else
    {
     for(int i = -n/2;i<= n/2 ; i++)
        {
          if(i == 0) continue;
          else temp.push_back(i);
        }
    }    
    }
    return temp;    
    }
};