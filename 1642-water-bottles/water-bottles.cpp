class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    ios::sync_with_stdio(false);
    cin.tie(0);
     return    ( numBottles + ( numBottles - 1 ) / (numExchange-1) );
    }
};