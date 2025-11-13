class Solution {
public:
    int maxOperations(string s) {
    int count = 0;
    int operations = 0;
    int n = s.length();
    for(int i = 0 ; i < n-1 ; i++)
    {   
        if(s[i] == '0' && s[i+1] == '1') operations+=count;
        else if(s[i] == '1') count++;
        
    }
    if(s[n-1] == '0')  operations+=count;
    return operations;
    }
};