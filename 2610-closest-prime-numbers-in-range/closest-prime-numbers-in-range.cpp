class Solution {
public:
    bool isPrime(int n)
    {
      if(n == 1) return false;
      for(int i = 2; i <= pow(n,0.5);i++)
      {
      if(n % i == 0) return false;
      }
      return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime;
       for(int i = left; i <= right ; i++)
       {
        if(isPrime(i))
        {
        prime.push_back(i);
        }
       }
       int idx = -1;
       int mini = INT_MAX;
       int temp = mini;
    //    for(int i = 0 ; i < prime.size();i++)
    //    {
    //     cout<<prime[i]<<" ";
    //    }
       for(int i = 1 ; i < prime.size();i++)
       {
       
       mini = min(mini,prime[i] - prime[i-1]);
       if(temp != mini)
       {
        idx = i-1;
        temp = mini;
       }
       }
       vector<int>ans(2,-1);
       if(prime.size() <= 1 ) return ans;
       ans[0] = prime[idx];
       ans[1] = prime[idx+1];
       return ans;
    }
};