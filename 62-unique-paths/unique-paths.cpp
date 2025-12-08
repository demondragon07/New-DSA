class Solution {
public:
 int solve(int m, int n,vector<vector<int>>&dp){
     dp[0][0]=1;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
           else{ 
           int up=i-1>=0?dp[i-1][j]:0;
           int left=j-1>=0?dp[i][j-1]:0;
           dp[i][j]=up+left;
           }
        }
     }
   return dp[m-1][n-1];
 }
  

    int uniquePaths(int m, int n) {
     vector<vector<int>>dp(m,vector<int>(n,-1));
     return solve(m,n,dp);  
    }
};