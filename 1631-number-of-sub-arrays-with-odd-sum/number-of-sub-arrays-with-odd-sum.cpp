class Solution {
public:
    const int M = 1000000000 + 7;
    int numOfSubarrays(vector<int>& arr) 
    {
    int n = arr.size();
    vector<int>prefix(n,0);
    prefix[0] = arr[0];
    for(int i = 1; i<n;i++)
    {
     prefix[i] = prefix[i-1] + arr[i];
    }    
    int even = 1;
    int odd = 0;
    int count = 0;
    for(int i = 0;i < n ;i++)
    {
        if(prefix[i] % 2 == 0) // odd = even + odd
        {
            count = (count + odd)% M;
            even++;
        }
        else // odd = odd + even
        {
           count = (count + even) % M;
           odd++;
        }
    }
    return count;
    }
};