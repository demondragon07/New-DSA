class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int zeros=0;
        int ans=0;
        int len=0;
        while(r<n){
            if(nums[r]==0)zeros++;
            if(zeros<=k){
                len=r-l+1;
                ans=max(len,ans);
            }else{
                while(zeros>k){
                    if(nums[l]==0)zeros--;
                   l++;
                }
            }
            r++;
        }
        return ans;
    }
};