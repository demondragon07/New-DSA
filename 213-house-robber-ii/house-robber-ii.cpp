class Solution {
public:
    int rob(vector<int>& nums){
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
       int prevkaprev=0;  
       int prev=0;      
       // if 1st house is taken;
        for(int i=1;i<=n-1;i++){
            int steal=nums[i-1]+ prevkaprev;
            int skip=prev;
            int curr=max(steal,skip);
            prevkaprev=prev;
            prev=curr;
        }
       int result1=prev;

       // if 1st house is not taken
      int prevkaprev2=0;
      int prev2=0;
       for(int i=2;i<=n;i++){
          int steal=nums[i-1]+prevkaprev2;
          int skip=prev2;
          int curr2=max(steal,skip);
          prevkaprev2=prev2;
          prev2=curr2;
       }
       int result2=prev2;
       return max(result1,result2);
    }
};