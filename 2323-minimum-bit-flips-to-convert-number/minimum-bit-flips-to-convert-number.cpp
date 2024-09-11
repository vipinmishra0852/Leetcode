class Solution {
public:
    int minBitFlips(int start, int goal) 
    {   if(start == 0 && goal == 0) return 0;
        int x = max(start,goal);
        int n = floor( log2 ( x  ) ) + 1;
        int ans = start ^ goal;
        int result =  __builtin_popcount(ans);
        return  result;
    }
};