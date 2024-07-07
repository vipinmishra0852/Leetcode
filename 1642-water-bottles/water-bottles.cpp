class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
    int count = 0;
    count = count + numBottles;
    
    while(numBottles >= numExchange)
    {
     int rem = numBottles % numExchange ;
     int div = numBottles / numExchange ; 
      count = count + div;
      if(div + rem >= numExchange)
      {
       numBottles = div + rem;
      }
      else break;
    }    
    return count;
    }
};