class Solution {
public:
    int reverse(int x) {
       int ans=0;
       bool isnegative=false;
       if(x<=INT_MIN){
          return 0;
      }
       if(x<0){
        x=-x;
        isnegative=true;
       }
       while(x>0){
         int digit=x%10;
        if((ans>INT_MAX/10) ||  (ans==INT_MAX/10 && (digit==8 || digit==9))){
            return 0;
        }
        ans=ans*10+digit;
        x=x/10;
       }

      return isnegative?-ans:ans;
    }
};