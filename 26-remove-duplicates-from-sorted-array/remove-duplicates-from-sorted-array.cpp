class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        int i=1;
         while(i<nums.size()){
            if(nums[i]==nums[j]) i++;
            else nums[++j]=nums[i++]; 
        }
        return j+1;
    }
};