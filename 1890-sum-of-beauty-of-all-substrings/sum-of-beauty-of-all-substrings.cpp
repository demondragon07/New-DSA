class Solution {
public:
    void solve(string &s , map<char,int>&mp,int &ans){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto x:mp){
            if(x.second>maxi)maxi=x.second;
            if(x.second<mini)mini=x.second;
        }
        ans+=maxi-mini;
    }
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                solve(s,mp,ans);
            }
        }
        return ans;
    }
};