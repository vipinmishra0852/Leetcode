class Solution {
public:
    int findClosest(int x, int y, int z) {
     int diff_1 = abs(z-x);
     int diff_2 = abs(z-y);
     if(diff_1 == diff_2) return 0;
     else if(diff_1 > diff_2) return 2;
     return 1;     
    }
};