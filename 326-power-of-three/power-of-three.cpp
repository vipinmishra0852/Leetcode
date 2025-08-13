class Solution {
public:
    bool isPowerOfThree(int n) {
      if(n <= 0) return false;
      if(n == 1) return true;
      double temp = (double)n;
      while(temp > 0)
      { 
        temp = temp/3;
        if(temp == 1.0 ) return true;
      }
      return false;  
    }
};