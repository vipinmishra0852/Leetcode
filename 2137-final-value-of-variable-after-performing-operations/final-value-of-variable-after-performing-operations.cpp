class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
     int n = operations.size();
     int ans = 0;
     for(string temp:operations)
     {
        if(temp=="--X" || temp == "X--" ) ans--;
        else ans++;
     }    
     return ans;
    }
};