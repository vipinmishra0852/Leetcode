class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        int i=0;
        while(i<n){
            if(abs(s[i]-s[i+1])==32){
                s.erase(i,2);
                i=0;
                n=n-2;
            }
            else{
            i++;
            }
        }
        return s;
    }
};