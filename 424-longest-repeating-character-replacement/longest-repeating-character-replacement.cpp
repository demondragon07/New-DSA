class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxlen=0;
        int change=0;
        int maxfreq=0;
        vector<int>v(26,0);
        int l=0;
        int r=0;
        while(r<n){
            v[s[r]-'A']++;
            maxfreq=max(maxfreq,v[s[r]-'A']);
            change=(r-l+1)-maxfreq;
            if(change<=k) maxlen=max(maxlen,r-l+1);
            else{
                v[s[l]-'A']--;
                maxfreq=0;
                for(int i=0;i<26;i++){
                    maxfreq=*max_element(v.begin(),v.end());
                }
                l++;
            }
            r++;
        }
      return maxlen;
    }
};