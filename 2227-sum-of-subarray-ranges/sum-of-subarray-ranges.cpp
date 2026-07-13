class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n=nums.size();
        long long total=0;
        for(long long i=0;i<n;i++){
            int  maxii=nums[i];
            int minii=nums[i];
            for(long long j=i;j<n;j++){
                maxii=max(maxii,nums[j]);
                minii=min(minii,nums[j]);
                total+=maxii-minii;
            }
        }
        return total;
    }
};