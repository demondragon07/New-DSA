class Solution {
public:
   void firstoccurence(vector<int>&nums,int &ansindex,int target){
       int s=0;
       int e=nums.size()-1;
       while(s<=e){
          int mid=s+(e-s)/2;
           if(nums[mid]==target){
            ansindex=mid;
             e=mid-1;
           }
           
           else if(nums[mid]>target){
              e=mid-1;
           }else{
            s=mid+1;
           }
       }
   }

   void lastoccurence(vector<int>&nums, int&ansindex ,int target){
         int s=0;
         int e=nums.size()-1;
         while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                ansindex=mid;
                s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }else{
              s=mid+1;
            }
         }
   }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v(2,-1);
        int ansindex=-1;
        firstoccurence(nums,ansindex,target);
        v[0]=ansindex;
        ansindex=-1;
        lastoccurence(nums,ansindex,target);
        v[1]=ansindex;
    return v;
    }
};