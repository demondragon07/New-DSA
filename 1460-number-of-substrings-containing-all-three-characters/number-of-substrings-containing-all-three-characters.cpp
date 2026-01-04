class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastA=-1;
        int lastB=-1;
        int lastC=-1;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')lastA=i;
            else if(s[i]=='b')lastB=i;
            else if(s[i]=='c')lastC=i;
            int mini=min({lastA,lastB,lastC});
            if(mini!=-1){
                ans=ans+1+mini;
            }
        }
        return ans;
    }
};