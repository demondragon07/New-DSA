class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=mp[nums[i]]+1;
        }
        for(auto x:mp){
            if(x.second==1){
                return x.first;
            }
        }
     return -1;   
    }
};