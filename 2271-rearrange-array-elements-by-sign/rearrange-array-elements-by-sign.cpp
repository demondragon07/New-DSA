class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     int n=nums.size();
       vector<int>pos;
       vector<int>neg;
       for(int k=0;k<n;k++){
        if(nums[k]>0) pos.push_back(nums[k]);
        else neg.push_back(nums[k]);
       }
       bool ispos=true;
       int i=0;
       int j=0;
       vector<int>ans;
        while(n){
         if(ispos) {
            ans.push_back(pos[i]);
            i++;
            ispos=false;
        }else{
            ans.push_back(neg[j]);
            j++;
            ispos=true;
        }
        n--;
       }
      return ans; 
    }
};