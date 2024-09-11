class Solution {
public:
    string convertDateToBinary(string date) 
    {
      string year = date.substr(0,4);
      string month = date.substr(5,2);
      string dat = date.substr(8,2);
      int y = stoi(year);
      int m = stoi(month);
      int d = stoi(dat);
      string r1,r2,r3;
      while(y)
      {
        int r = y%2;
        y = y/2;
        r1 = to_string(r) + r1; 
      }
       while(d)
      {
        int r = d%2;
        d = d/2;
        r2 = to_string(r) + r2; 
      }
       while(m)
      {
        int r = m%2;
        m = m/2;
       r3 = to_string(r) + r3; 
      }
      return (r1+ '-' + r3 + '-' + r2);
    }
};