class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int result=0;
        int i=0;
        int j=0;
        long long windowsum=0;
        int prefixzeros=0;
        while(j<n){
            windowsum+=nums[j];
            while(i<j && (nums[i]==0 || windowsum>goal)){
               if(nums[i]==0) prefixzeros++;
               else prefixzeros=0;
               windowsum-=nums[i];
               i++;
            }
            if(windowsum==goal){
                result+=1+prefixzeros;
            }
            j++;
        }
        return result;
    }
};