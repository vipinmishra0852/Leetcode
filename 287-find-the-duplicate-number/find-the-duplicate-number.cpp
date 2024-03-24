class Solution {
public:
    int findDuplicate(vector<int>& nums) {
          ios::sync_with_stdio(false); 
  cin.tie(nullptr);            
  cout.tie(nullptr);
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
        m[nums[i]]++;
        }
        int s=0;
        for(auto it:m){
            if(it.second>=2){
               s=it.first;
               break;
            }
        }
        return s;

    }
};