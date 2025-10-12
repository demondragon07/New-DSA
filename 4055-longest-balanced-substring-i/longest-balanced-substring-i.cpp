class Solution {
public:
    int solve(unordered_map<char,int>&mp){
        int MAXI=INT_MIN;  
        int MINI=INT_MAX;
        for(auto x:mp){
            MAXI=max(x.second,MAXI);
            MINI=min(x.second,MINI);
        }
        return MAXI==MINI;
    }
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
           for(int j=i;j<n;j++){
               mp[s[j]]++;
               if(solve(mp)){
                ans=max(ans,j-i+1);
               }
           }
        }
        return ans;
    }
};