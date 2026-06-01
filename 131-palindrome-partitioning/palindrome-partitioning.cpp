class Solution {
public:
   
    void findallcombos(vector<vector<string>>&ans,vector<string>ds,string s, int idx){
        if(idx==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<s.size();i++){
           if(ispalindrome(s,idx,i)){
             ds.push_back(s.substr(idx,i-idx+1));
             findallcombos(ans,ds,s,i+1);
             ds.pop_back();               
           }
        }
    }

    bool ispalindrome(string s , int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        findallcombos(ans,ds,s,0);
        return ans;
    }
};