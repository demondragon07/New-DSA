class Solution {
public:
    int reverse(int x) {
        int mini=INT_MIN/10;
        int maxi=INT_MAX/10;
        int ans=0;
        while(x){
            int rem=x%10;
            if(ans>maxi || ans<mini)return 0;
            ans=ans*10+rem;
          x/=10;
        }
        return ans;
    }
};