class Solution {
public:
     void search(vector<int>&nums,int firstelement,int j, int target,set<pair<int,int>>&ans){
        int s=j;
        int e=nums.size()-1;
        while(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid]==target){
            ans.insert({firstelement,nums[mid]});
            return;
        } 
        else if(nums[mid]>target)
           e=mid-1;
        else
          s=mid+1;
       }
     } 
    
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<pair<int,int>>ans;
        for(int i=0;i<n;i++){
           int  target=nums[i]+k;
        search(nums,nums[i],i+1,target,ans);
        }
       return ans.size(); 
    }
};