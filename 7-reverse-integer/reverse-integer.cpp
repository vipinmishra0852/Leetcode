class Solution {
public:
int reversed(int x){
     string s=to_string(x);
     string revSt="";
    for(int i=s.size()-1;i>=0;i--){
      revSt=revSt+s[i];
    }
      try {
         
            return stoi(revSt);
        } catch (out_of_range& e) {
            return 0;  
        }

    
}
    int reverse(int x) {
            if(x<0){
           
               int w= reversed(x);
                int e=w*(-1);
                return e;
            
            }
            if(x>0){
              int w=reversed(x);
         
                return w;
            }
        return 0;
    }
};