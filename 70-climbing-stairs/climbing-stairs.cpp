class Solution {
public:
 long long int nCr(int N, int r)
{
    long long res = 0;
    if (r == 0) {
        return 1;
    }
    else {
        res = nCr(N, r - 1)
              * (N - r + 1) / r;
    }
    return res;
}
    int climbStairs(int n) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int N=0;
        int r=0;
         long long Res=0;
        if(n%2==0){
          N=n/2;
            r=0;
            Res=1;
        }
        else{
            N=(n/2)+1;
            r=1;
            Res=1;
        }
       
       while(N>r){
            Res=Res+nCr(N,r);
           N++;
           r+=2;
       }
        return Res;
    }
};