class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base:: sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
    vector<int>v(n+1,0);
    vector<int>ans;
    for(int i=0;i<n;i++){
        v[nums[i]]++;
    }
    for(int i=0;i<n+1;i++){
        if(v[i]==2) {
        ans.push_back(i);
        }
    }
    return ans;
    }
};