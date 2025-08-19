class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int product=1;
        int count=0;
        int n=nums.size();
        if(k<=1){
            return 0;
        }
        while(j<n){
            product*=nums[j];
            while( i<=j && product>=k){
                product/=nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
};