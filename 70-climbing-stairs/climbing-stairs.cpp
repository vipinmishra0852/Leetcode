class Solution {
public:
 vector<int>dp;
 int Stairs(int n)
{ 
    
    if(n==2) return dp[n] = 2;
    if(n==1) return dp[n] =  1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = Stairs(n-1)+Stairs(n-2);
    
}
int climbStairs(int n){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp.resize(n+1,-1);
    return Stairs(n);
}

};