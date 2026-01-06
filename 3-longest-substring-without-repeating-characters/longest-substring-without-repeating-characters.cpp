class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            int len=0;
            for(int j=i;j<n;j++){
              st.insert(s[j]);
              len=j-i+1;
              if(len==st.size())ans=max(ans,len);
              else break;
            }
        }
        return ans;
    }
};