class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        while(s<=e){
            long long mid=s+(e-s)/2;
            long long prod=mid*mid;
            if(prod==x){
                return mid;
            }
            if(prod>x){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
      return e;
    }
};