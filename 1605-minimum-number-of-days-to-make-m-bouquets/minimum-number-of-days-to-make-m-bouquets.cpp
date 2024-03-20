class Solution {
public:
        
    int check(int mid, long long k,int n, vector<int>& bloomDay) {
       
        int ct=0;
        int total=0;
        for(int i = 0; i < n; i++) {
            if(mid>=bloomDay[i]){
                    ct++;
                    if(ct==k){
                        total++;
                        ct=0;
                    }
                    }
            else {
                ct=0;
            }
        }
        return total;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
           int maxi =0;
           
            for(int i=0;i<n;i++){

        maxi = max(maxi,bloomDay[i]);
        
                    }
                    long long t= (long long )m*(long long) k;
        if(n < t) return -1;
        int lo=1;
        int hi = maxi;
        int ans = INT_MAX;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(check(mid,k,n,bloomDay)>=m) {
                ans = min(mid,ans);
                 hi = mid - 1;
              
            }
             else
              {
                 lo = mid + 1;
            }
        }
        return ans;
    }
};