class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>n/3){
                ans.push_back(nums[i]);
            }
        }
        unordered_set<int>s;
        for(auto x:ans){
            s.insert(x);
        }
        vector<int>result;
        for(auto x:s){
            result.push_back(x);
        }
       return result; 
    }
};