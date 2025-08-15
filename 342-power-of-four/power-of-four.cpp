class Solution {
public:
    bool isPowerOfFour(int n) 
    {
    
    if(n <= 0) return false;
    if(n == 1) return true;
    double temp  = (double)n;
     cout<<"temp loop ke bahar gya"<<endl;
    while(temp >= 1.0)
    {
     cout<<"temp loop mein gya"<<endl;
     if(temp == 1.0)
     {
        return true;
     }
     cout<<"temp before divide "<<temp<<endl;
     temp/=4;
     cout<<"temp after divide "<<temp<<endl;

    }
    cout<<"exit"<<endl;
    return false;    
    }
};