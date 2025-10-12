class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int result=0;
        for (auto &x:mp){
            if((x.second)%k==0) result+=(x.first*x.second);
        }
        return result;
    }
};