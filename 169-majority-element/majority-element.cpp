class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int result=n/2+1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>=result){
                return nums[i];
            }
        }
        return -1;
    }
};