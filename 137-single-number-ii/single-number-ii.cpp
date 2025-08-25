class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<=31;k++){
            int temp=(1<<k);
            int countzeros=0;
            int countones=0;
            for(auto num:nums){
             if(num&temp)countones++;
             else countzeros++;
            }
          if(countones%3!=0){
            result=result|temp;
          }
        }
        return result;
    }
};