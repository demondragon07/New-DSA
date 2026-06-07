class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int b0=0;
        int b1=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
          ans=ans^nums[i];
        }
        long long lastsetbit=((ans&(ans-1))^(ans));
        for(int i=0;i<nums.size();i++){
            if((lastsetbit&nums[i])==0)b0=b0^nums[i];
            else b1=b1^nums[i]; 
        }
        return {b0,b1};
    }
};