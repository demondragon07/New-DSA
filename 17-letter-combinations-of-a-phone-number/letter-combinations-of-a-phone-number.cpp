class Solution {
public:
   void solve(vector<string>&ans,string digits ,int idx,string temp,unordered_map<char,string>&mp){
         if(idx>=digits.size()){
            ans.push_back(temp);
            return;
         }
         char ch=digits[idx];
         string s=mp[ch];
         for(int i=0;i<s.length();i++){
            temp.push_back(s[i]);
            solve(ans,digits,idx+1,temp,mp);
            temp.pop_back();
         }
   }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
      solve(ans,digits,0,temp,mp);
     return ans;
    }
};