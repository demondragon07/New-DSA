class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int cumsum=0;
        int result=0;
        for(int i=0;i<n;i++){
           cumsum+=nums[i];
           if(mp.find(cumsum-goal)!=mp.end()){
              result+=mp[cumsum-goal];
           }
          mp[cumsum]++;
        }
        return result;
    }
};