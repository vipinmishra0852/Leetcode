class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
    int N = nums.size();    
    int n = N/3;
    vector<long long>leftMinSum(N,0);
    vector<long long > rightMaxSum(N,0);
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    long long leftSum = 0;
    long long rightSum = 0;
    for(int i = 0 ; i < 2*n ; i++)
    {
     left.push(nums[i]);
     leftSum += nums[i];
     if(left.size() > n )
     {
        leftSum -= left.top();
        left.pop();
     }
     leftMinSum[i] = leftSum;
    }

     for(int i = N-1 ; i >= n ; i--)
    {
     right.push(nums[i]);
     rightSum += nums[i];
     if(right.size() > n )
     {
        rightSum -= right.top();
        right.pop();
     }
     rightMaxSum[i] = rightSum;
    }
    long long result = LLONG_MAX;
    for(int i = n-1; i <= 2*n -1 ; i++)
    {
     result  = min(result,leftMinSum[i] - rightMaxSum[i+1]);
    }
    return result;
    }
};