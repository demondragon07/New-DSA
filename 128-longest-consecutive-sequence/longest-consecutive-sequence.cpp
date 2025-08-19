class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        for(auto x:nums){
            mp[x]=false;
        }
        int maxlength=0;
        for(int i=0;i<nums.size();i++){
            int currentlength=1;
            int x=nums[i];
            mp[x]=true;
            int num1=x+1;
            while(mp.find(num1)!=mp.end() && mp[num1]==false){
              currentlength++;
              mp[num1]=true;
              num1++;
            }
           int num2=x-1;
           while(mp.find(num2)!=mp.end() && mp[num2]==false){
              currentlength++;
              mp[num2]=true;
              num2--;
           }
           maxlength=max(maxlength,currentlength);
        }

        return maxlength;
    }
};