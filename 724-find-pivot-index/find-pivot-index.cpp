class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>lsum(n,0);
        vector<int>rsum(n,0);

        for(int i=1;i<n;i++){
            lsum[i]=lsum[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rsum[i]=rsum[i+1]+nums[i+1];
        }

        for(int i=0;i<n;i++){
            if(lsum[i]==rsum[i]){
                return i;
            }
        }

        return -1;
    }
};