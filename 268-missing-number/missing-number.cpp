class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        bool isone=false;
        for(int i=0;i<n;i++){
          if(nums[i]==1){
            isone=true;
          }
          if(nums[i]==0){
            nums[i]=1;
          }
        }

        if(isone!=true){
            return 1;
        }
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            int idx=num-1;
            
           if(nums[idx]<0)continue;

           nums[idx]*=-1; 
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }

        return 0;
    }
};