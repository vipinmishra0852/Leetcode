
class Solution {
public:
    #define LL long long
    LL check(vector<int>&time,LL mid)
    {
    LL sum = 0;
    for(int i = 0;i<time.size();i++)
    {
    sum = sum + mid/time[i];
    }
    return sum;
    }
    
    LL minimumTime(vector<int>& time, int totalTrips) 
    {
        sort(time.begin(),time.end());
        LL lo = 1;
        LL hi = (LL)time[0]*totalTrips;
        LL mid = lo  + (hi-lo)/2;
          LL ans = hi;
        while(lo<=hi)
        {
            mid = lo + (hi-lo)/2;
            LL dekho = check(time,mid);
          
            if(totalTrips <= dekho)
            {
             ans = mid;
             hi = mid - 1;
            }
            else { lo = mid+1;}
           
        }
        return ans;

    }
};