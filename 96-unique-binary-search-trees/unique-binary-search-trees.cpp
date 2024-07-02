class Solution {
public:
    int helper(int n)
    {
        if(n == 0 || n == 1) return 1;
        if( n == 2) return 2;
        int sum = 0;
        for(int k = 1; k<=n ; k++)
        {
            sum += helper(k-1) * helper(n-k);
        } 
        return sum;
    }
    int numTrees(int n)
    {
    int ans = helper(n);
    return ans;
    }
};