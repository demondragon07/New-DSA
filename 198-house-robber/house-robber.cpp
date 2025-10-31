class Solution {
public:
    int rob(vector<int>& nums){
     vector<int>t(101,0);
       int n=nums.size();
     //t[i]=Max profit till ith house;
       int prevkaprev=0;
       int prev=nums[0];
     for(int i=2;i<=n;i++){
        int steal=nums[i-1]+prevkaprev;
        int skip=prev;
        int curr=max(steal,skip);
        prevkaprev=prev;
        prev=curr;
     }
      return prev;
    }
};