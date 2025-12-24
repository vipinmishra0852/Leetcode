class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) 
    {
     sort(capacity.begin(),capacity.end());
     int n = apple.size();
     int m = capacity.size();
     int sum = accumulate(apple.begin(),apple.end(),0);
     cout<<sum<<"-> sum"<<endl;
     int temp = 0;
     for(int i = m-1 ; i >= 0 ; i--)
     {
        temp+=capacity[i];
        cout<<"temp -> "<<temp<<", i -> "<<i<<endl;
        if(temp >= sum) return (m-i);
     }
     return -1;   
    }
};