class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int n=s.size();
        unordered_map<char,int>mp;
        int cnt=0;
        int len=INT_MAX;
        int si=-1;
        for(int i=0;i<t.size();i++)mp[t[i]]++;
        while(r<n){
           if(mp[s[r]]>0)cnt++;
              mp[s[r]]--;
           while(cnt==t.size()){
             mp[s[l]]++;
             if(len>r-l+1){
                len=r-l+1;
                si=l;
             }
             if(mp[s[l]]>0)cnt--;
             l++;
           }
           r++;
        }
       return si==-1?"":s.substr(si,len);
    }
};