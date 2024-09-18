class Solution {
public:
    static bool compare(string &x,string &y){
        return x+y>y+x;
    }
    string largestNumber(vector<int>& nums) 
    {
    vector<string>v;
    int n = nums.size();
    for(int i = 0 ; i <n;i++)
    {
    v.push_back(to_string(nums[i]));
    }
    sort(v.begin(),v.end(),compare);   
     if (v[0] == "0") return "0";
        
    string result="";
    for(string s:v)
    {
    result+=s;
    } 
    return result;
    }
};