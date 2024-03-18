class Solution {
public:
    bool isSquare(int n){
        int t=(int)sqrt(n)*(int)sqrt(n);
        if(t==n) return true;
        else return false;
    }
    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
       if(isSquare(x) && isSquare(y)){
        return true;
       }
       else if(!isSquare(y)){
        y=(int)sqrt(y)*sqrt(y);
        x=c-y;
       }
       else{
        x=((int)sqrt(x)+1)*((int)sqrt(x)+1);
        y=c-x;
       }
        }
        return false;
    }
};