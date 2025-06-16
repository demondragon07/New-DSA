class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=i+k-1;
        double sum=0;
        for(int k=0;k<=j;k++){
          sum+=nums[k];
        }
        double maxsum=sum;
        
        
       while(j<n-1){
          j++;
          i++;
          sum+=nums[j]-nums[i-1];
          if(sum>maxsum){
            maxsum=sum;
          }
       }

       return maxsum/k;
    }
};