class Solution {
public:
    int scoreOfString(string s) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s.size();
        int sum=0;
        for(int i=0;i<n-1;i++)
        {
           sum=sum+abs(s[i]-s[i+1]);
        }
        return sum;
    }
};