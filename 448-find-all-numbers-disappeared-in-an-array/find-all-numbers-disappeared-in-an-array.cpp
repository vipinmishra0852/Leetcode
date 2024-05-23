class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // ios::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int n=nums.size();
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++){
            v[nums[i]]=1;
        }
        vector<int>ans;
        for(int i=1;i<n+1;i++){
            if(v[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};