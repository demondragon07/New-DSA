class Solution {
public:
    bool binarysearch(int s, int e, vector<int>&nums,int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                 return true;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int s=0;
        int n=nums.size();
        int e=n-1;
        while(s<e){
            while(s<e && nums[s]==nums[s+1]){
                s++;
            }
            while(s<e && nums[e]==nums[e-1]){
                e--;
            }
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[e]){
                s=mid+1;
            }else
             e=mid;
        }
        int index=s;
        bool ans;
        if(target>=nums[0] && index-1>=0 && target<=nums[index-1]){
            ans=binarysearch(0,index-1,nums,target);
        }else{
            ans=binarysearch(index,n-1,nums,target);
        }
      return ans;
    }
};