class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long product=1;
        int m=n;
        while(n){
            int digit=n%10;
            sum+=digit;
            product*=digit;
            n=n/10;
        }
        return (m%(sum+product)==0);
    }
};