class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_set<char>st;
        int n=t.length();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                if(st.find(t[i])==st.end()){
                    st.insert(t[i]);
                }else return false;
                 mp[s[i]]=t[i];
            }
            else  if(mp[s[i]]!=t[i])return false;
        }

        return true;
    }
};