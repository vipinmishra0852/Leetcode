class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int suf[n];
        suf[n-1]=satisfaction[n-1];

        for(int i=n-2;i>=0;i--){
         suf[i]=suf[i+1]+satisfaction[i];
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            if(suf[i]>=0){
             idx=i;
             break;
            }
        }
        if(idx==-1) return 0;
        int ans=0;
        int mul=1;
        for(int i=idx;i<n;i++){
        ans=ans+(mul*satisfaction[i]);
        mul++;
        }
        return ans;
        
    }
};