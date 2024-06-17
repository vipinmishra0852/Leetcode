class Solution {
public:
long long reverseInt(long long n)
{
    long long digit=0;
    while(n>0)
    {   long long r=n%10;
        digit=digit*10+r;
        n/=10;
    }
    return digit;
}
    int countNicePairs(vector<int>& nums)
    {
    long long n = nums.size();
    map<long,long>m;
    long long count = 0;
    for(int i=0;i<n;i++)
    {  long long x = reverseInt((long long)(nums[i]));
       m[nums[i]-x]++;
    }
    for(auto i:m)
    {
        if(i.second>=2)
        {   
            long long z = i.second;
            if(z==2)
            {
                count++;
            }
            else
            {
                count = ( count % (1000000000 + 7) + (((z-1) * z) / 2)%(1000000000 + 7))%(1000000000 + 7);
            }
        }
    }
      return count%(1000000000 + 7);  
    }
};