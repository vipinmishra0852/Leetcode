class Solution {
public:
    int countOdds(int low, int high) {
    int count  = 0 ;
    bool koioddhai = false;
    if((low%2 != 0) || (high%2 != 0)) koioddhai = true;
    count = (high - low)/2;
    return koioddhai?count+1:count;
    }
};