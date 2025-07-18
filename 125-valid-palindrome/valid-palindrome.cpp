class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
               ans.push_back(s[i]);
            }
        }

        int l=0;
        int r=ans.length()-1;
        while(l<=r){
            if(ans[l]==ans[r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
       return true; 
    }
};