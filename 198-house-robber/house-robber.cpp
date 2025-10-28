class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(101,0);
        int n=nums.size();
        //dp[i]=max_steal a person can do till house [i];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int take=nums[i-1]+dp[i-2];
            int skip=dp[i-1];
           dp[i]=max(take,skip);    
        }   
       return dp[n];
    }
};