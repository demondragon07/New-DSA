class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){ 
            int ones=0;
            int zero=0; 
           for(auto num:nums){
              if(num & (1<<i))ones++;
              else zero++;
           }
           if(ones%3)res=(res|(1<<i));
        }
        return res;
    }
};