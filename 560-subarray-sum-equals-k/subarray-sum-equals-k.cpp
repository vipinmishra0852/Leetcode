class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int result=0;
        int conSum=0;
        mp.insert({0,1});
        for(int i=0;i<nums.size();i++){
           conSum+=nums[i];
           if(mp.find(conSum-k)!=mp.end()){
               result+=mp[conSum-k];

           }
           mp[conSum]++;
        }
        return result;
    }
};