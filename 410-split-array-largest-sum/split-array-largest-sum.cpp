class Solution {
public:
    bool ispossible(vector<int>& nums, int mid, int k){
       int currsum=0;
       int n=nums.size();
       int p=1;
       for(int i=0;i<n;i++){
         if(nums[i]>mid) return false;
         currsum+=nums[i];
         if(currsum>mid){
            p++;
            currsum=nums[i];
         }
         if(p>k) return false;
       }
       return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int e=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        int n=nums.size();
        while(s<=e){
              if(k>n) return ans;
            int mid=s+(e-s)/2;
            if(ispossible(nums,mid,k)){
                   ans=mid;
                   e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};