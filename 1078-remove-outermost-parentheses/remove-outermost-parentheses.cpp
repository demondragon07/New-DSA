class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        string start;
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' && cnt==0){
                cnt++;
            }
            else if(s[i]==')' && cnt==1){
                cnt--;
                ans+=start;
                start.clear();
            }
            else{
                start+=s[i];
                if(s[i]=='(')cnt++;
                if(s[i]==')')cnt--;
            }
        }
        return ans;
    }
};