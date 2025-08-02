class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<bool>prime(n,true);
        prime[0]=false;
        prime[1]=false;
        int ans=0;
        for(int i=2;i<n;i++){
            if(prime[i])
            ans++;
            int j=i*2;
            while(j<n){
                prime[j]=false;
                j+=i;
            }
        }
       return ans; 
    }
};