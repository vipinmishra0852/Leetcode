class Solution {
public:
    string convertkro(int n)
    {
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;

    }
    bool reorderedPowerOf2(int n)
    {
     string check = convertkro(n);
     for(int i = 0 ; i <= 30 ; i++)
     {
        if(check == convertkro(1<<i))
        {
            return true;
        }
     }
     return false;
    }
};