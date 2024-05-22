class Solution {
public:
vector<string>generate(vector<string>&ans,string s,int open,int close,int n)
{
  if(close==n) {
    ans.push_back(s);
  }
  if(open<n) generate(ans,s+'(',open+1,close,n);
  if(close<open) generate(ans,s+')',open,close+1,n);
  return ans;
}
    vector<string> generateParenthesis(int n) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        string s="";
        vector<string>ans;
       return generate(ans,s,0,0,n);
      
    }
};