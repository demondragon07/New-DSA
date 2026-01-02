class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans=strs[0];
       string temp="";
       int n=strs.size();
       string temp1=strs[0];
       for(int i=1;i<n;i++){
        string temp2=strs[i];
        for(int j=0;j<min(temp1.length(),temp2.length());j++){
            if(temp1[j]==temp2[j]){
                temp+=temp1[j];
            }
            else break;
        }
        if(temp.length()<ans.length()){
           ans=temp;
        }
        temp.erase(0,temp.length());
       }
       return ans;     
    }
};