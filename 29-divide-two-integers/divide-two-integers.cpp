class Solution {
public:
    int divide(int dividend, int divisor) {
        bool ispos=true;
        if(dividend==divisor)return 1;
        if(dividend<0 && divisor>0) ispos=false;
        if(dividend>0 && divisor<0) ispos=false;
         
         long long divi=llabs(dividend);
         long long ds=llabs(divisor);
         long long ans=0;    
         while(divi>=ds){
             int cnt=0;
             while(divi>=ds<<(cnt+1)){
                cnt++;
             }
             ans+=(1LL<<cnt);
             divi=divi-(ds<<cnt);
         }
        if(ans>=INT_MAX && ispos) return INT_MAX;
        if(ans>INT_MAX && !ispos) return INT_MIN;
       
        return ispos?ans:-ans; 
    }
};