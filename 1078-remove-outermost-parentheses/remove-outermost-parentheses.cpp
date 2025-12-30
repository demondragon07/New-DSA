class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt!=0)ans+=s[i];
                cnt++;
            }
            if(s[i]==')'){
                cnt--;
                if(cnt!=0)ans+=s[i];
            }
        }
        return ans;
    }
};