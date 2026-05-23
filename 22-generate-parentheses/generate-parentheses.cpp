class Solution {
public:
  bool isvalid(string curr){
      int sum=0;
      int i=0;
      while(i<curr.size()){
        if(curr[i]=='(') sum+=1;
        if(curr[i]==')'){
            sum-=1;
            if(sum<0) return false;
        }
        i++;
      }
      return sum==0;
  }
 void solve(vector<string>&ans, int n , string curr){
        if(curr.size()==2*n){
            if(isvalid(curr)) ans.push_back(curr);
            return ; 
        } 
    curr.push_back('(');
    solve(ans,n,curr);
    curr.pop_back();
    curr.push_back(')');
    solve(ans,n,curr);
    curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(ans,n,"");
        return ans;
    }
};