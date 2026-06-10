class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        bool isneg=false;
        if(N<0){
           N=-1LL*n;
            isneg=true;
            }
         double ans=1;
         while(N){
            if(N%2==0){
                x=x*x;
                N/=2;
            }else{
                ans=ans*x;
                N=N-1;
            }
         }
         return isneg==true?1/ans:ans;
    }
};