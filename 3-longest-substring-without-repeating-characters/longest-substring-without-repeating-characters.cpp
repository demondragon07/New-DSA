class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        map<char,int>mp;
        int len=0;
        int ans=0;
        while(r<n){
          if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l){
            l=mp[s[r]]+1;
            mp[s[r]]=r;
          }
          else{
            mp[s[r]]=r;
            len=r-l+1;
            ans=max(ans,len);
          } 
       r++;
        }
        return ans;
    }
};