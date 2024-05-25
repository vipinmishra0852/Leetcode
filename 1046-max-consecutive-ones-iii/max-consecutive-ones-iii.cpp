class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        int i=0;
        int j=0;
        int length=INT_MIN;
        int maxlen=INT_MIN;
        int flips=0;
        while(j<n){
            if(nums[j]==1) j++;
            else
            {
              if(flips<k) 
              {
                flips++;
                j++;
              }
              else
              {
                length=j-i;
                maxlen=max(maxlen,length);
                while(nums[i]==1) {i++;}
                i++;  
                j++; 
              }
            }
          
        }
          length=j-i;
            maxlen=max(maxlen,length);
        return maxlen;

    }
};