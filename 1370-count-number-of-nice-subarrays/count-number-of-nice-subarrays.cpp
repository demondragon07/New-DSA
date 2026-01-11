class Solution {
public:
  int solve(vector<int>&nums,int k){
        int n=nums.size();
        if(k<0)return 0;
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        while(r<n){
           if(nums[r]%2!=0)sum++;
           while(sum>k){
               if(nums[l]%2!=0)sum--;
               l++;
           }
           cnt+=r-l+1;
           r++;
        }
        return cnt;
  }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};