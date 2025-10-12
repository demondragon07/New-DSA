class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int csum=nums[0]+nums[1];
        int ans=2;
        int result=2;
        for(int i=2;i<n;i++){
            if(csum==nums[i]){
                ans++;
                result=max(ans,result);
            } else ans=2;
             csum=nums[i]+nums[i-1];
        }
        return result;
    }
};