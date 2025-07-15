class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
           if(s==e){
            return nums[s];
           }
            int currval=nums[mid];
           int leftval=-1;
           if(mid-1>=0){
            leftval=nums[mid-1];
           }
           int rightval=-1;
           if(mid+1<n){
            rightval=nums[mid+1];
           }
         if(currval!=leftval && currval!=rightval){
            return currval; 
         }
         else if(currval==leftval){
            int startingindex=mid-1;
            if(startingindex &1){
                e=mid-1;
            }else{
                s=mid+1;
            }
         } else if(currval==rightval){
            int startingindex=mid;
            if(startingindex &1){
                e=mid-1;
            }else{
                s=mid+1;
            }
         }
        } 
       return -1; 
    }
};