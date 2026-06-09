class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return 0;
        long long ans=0;
        long long originalx=x;
        while(x){
            long long rem=x%10;
            ans=ans*10+rem;
            x/=10;
        }
        return ans==originalx;
    }
};