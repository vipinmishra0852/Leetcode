class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
    int n = derived.size();
    if(n == 1)
    {
        if(derived[0] == 0) return true;
        else return false;
    }
    if(n == 2)
    {
        if(derived[0] == derived[1]) return true;
        else false;
    }

    vector<int>v(n,0);
    if(derived[0] == 0)
    {
        v[0] = 0;
        v[1] = 0;
        for(int i = 1;i<n-1;i++)
        {
            if(derived[i] == 0)
            {
                if(v[i] == 0) v[i+1] = 0;
                else v[i+1] =1;
            }
            else
            {
                if(v[i] == 0) v[i+1] = 1;
                else v[i+1] = 0;
            }
        }

    }
    if(derived[0] == 1)
    {
        v[0] = 0;
        v[1] = 1;
        for(int i = 1;i<n-1;i++)
        {
            if(derived[i] == 0)
            {
                if(v[i] == 0) v[i+1] = 0;
                else v[i+1] = 1;
            }
            else
            {
                if(v[i] == 1) v[i+1] = 0;
                else v[i+1] = 1;
            }
        }

    }
    if(v[0] ^ v[n-1] == derived[n-1]) return true;
    return false;
        
    }
};