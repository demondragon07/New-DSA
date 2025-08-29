class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;
        bool ispositive=true;
        if(divisor<0 && dividend>0)
        {
             ispositive=false;
        }
        else if(divisor>0 && dividend<0){
            ispositive=false;
        }
        long long int divisorx=abs((long long)divisor);
        long long int dividendx=abs((long long)dividend);
        long long s=0;
        long long e=dividendx;
        long long ans=0;
        while(s<=e){
            long long mid=s+((e-s)>>1);
            if(divisorx*mid>dividendx){
                e=mid-1;
            }else {
                ans=mid;
                s=mid+1;
            }
        }
       if(ispositive) return (int)ans;
       return (int)-ans;
    }
};