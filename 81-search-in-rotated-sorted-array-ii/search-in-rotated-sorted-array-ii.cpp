class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int n=nums.size();
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                return true;
            } 
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return false;
    }

};