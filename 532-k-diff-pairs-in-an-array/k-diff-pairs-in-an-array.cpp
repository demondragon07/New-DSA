class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int j=1;
        int ans=0;
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        set<int>s;
        for(auto x:nums){
            s.insert(x);
        }
        vector<int>newnums;
        for(auto x:s){
            newnums.push_back(x);
        }
      
        if(k==0){
          for(auto x:newnums){
            if(mp[x]>1) ans++;
          }
          return ans;
        }
        int m=newnums.size();
        while(j<m){
            int diff=abs(newnums[j]-newnums[i]);
            if(diff==k){
                ans++;
                i++;
                j++;
            }
            else if(diff>k){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};