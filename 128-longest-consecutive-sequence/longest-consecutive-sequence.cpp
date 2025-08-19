class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums.empty()) return 0;
        int count=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1])==1){
                count++;
                ans=max(ans,count);
            }else if(nums[i]==nums[i-1]){
                continue;
            }else{
                count=1;
            }
        }
        return ans;
    }
};