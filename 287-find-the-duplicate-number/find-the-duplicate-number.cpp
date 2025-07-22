class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int ans=-1;     
      int n=nums.size();
      for(int i=0;i<n;i++){
        int numb=abs(nums[i]);
        int idx=numb-1;
      
        if(nums[idx]<0){
            ans=idx+1;
            break;
        }
        nums[idx]*=-1;
      }
    
    return ans;
    } 
};