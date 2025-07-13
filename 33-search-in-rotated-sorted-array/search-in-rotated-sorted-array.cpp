class Solution {
public:
    int pivotelement(vector<int>&nums){
        int s=0;
        int n=nums.size();
        int e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[e]){
                s=mid+1;
            }else{
                e=mid;
            }
        } 
   return s;
    }
    int binarysearch(vector<int>&nums,int s, int e, int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot=pivotelement(nums);
        int n=nums.size();
        int ans=-1;
        if(target>=nums[0] && pivot-1>=0 && target<=nums[pivot-1]){
           ans= binarysearch(nums,0,pivot-1,target);
        }else{
           ans= binarysearch(nums,pivot,n-1,target);
        }
        return ans; 
    }
};