class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int ans=0;
        for(int j=0;j<n;j++){
            if(nums[j]==1){
              count++;
            ans=max(count,ans);
        } else 
           count=0;
    }
   return ans;
    } 
};