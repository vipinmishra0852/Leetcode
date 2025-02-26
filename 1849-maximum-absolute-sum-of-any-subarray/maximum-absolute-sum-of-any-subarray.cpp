class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
    int MaxSum=0,MinSum=0,CurrMax=0,CurrMin = 0;
    for(int num:nums)
    {
        CurrMax += num;
        CurrMin += num;

        MaxSum = max(CurrMax,MaxSum);
        MinSum = min(CurrMin,MinSum);

        if(CurrMax < 0) CurrMax = 0;
        if(CurrMin > 0) CurrMin = 0;
    }
    return max(MaxSum,abs(MinSum));
    }
};