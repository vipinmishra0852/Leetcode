class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        int sum=0;
        int i=0;
        int j=0;
         int minlength=INT_MAX;
         int length=0;
        while(j<n)
        {
         sum+=nums[j];
          while(sum>=target){
             length=j-i+1;
             minlength = min(minlength,length);
             sum-=nums[i];
             i++;
          }
          j++;

        }
        if(minlength==INT_MAX){
            return 0;
        }
        return minlength;
        
    }
};