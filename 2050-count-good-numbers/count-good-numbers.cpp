class Solution {
public:
const long long MOD=1e9+7;
 int power(long long a, long long b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%MOD;
            b=b-1;
        }else{
            a=(a*a)%MOD;
            b=b>>1;
        }
    }
    return ans%MOD;
 }
    int countGoodNumbers(long long n) {
        long long evenidx=(n+1)/2;
        long long oddidx=(n/2);
        return ((power(5,evenidx)%MOD)*(power(4,oddidx)%MOD))%MOD;
    }
};