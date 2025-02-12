class Solution {
public:
    int find_sum(int num)
    {
        int summ = 0;
        while(num >= 1)
        {
            int r = num % 10;
            num = num / 10;
            summ = summ + r;
        }
     return summ;
    }
    int maximumSum(vector<int>& nums) 
    {
    int n = nums.size();
    map<int,int>m; // sum_of_digits,index
    int ans = -1;
    for(int i = 0 ; i < n ; i++)
    {
    int sum_of_digits = find_sum(nums[i]);
    if(m.find(sum_of_digits) != m.end())
    {
        int index = m[sum_of_digits];
        int sum = nums[index] + nums[i];
        ans = max(ans,sum);
        if(nums[i] > nums[index])
        {
            m[sum_of_digits] = i;
        }
    }
    else m.insert({sum_of_digits,i});
    }
    return ans;
    }
};