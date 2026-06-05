class Solution {
public:

    void solve(vector<string>&ans, string s, long long target, int i, const string &path, long long eval, long long resd){
        if(i==s.length()){
            if(eval==target)ans.push_back(path);
            return;
        }
        string currstr="";
        long long num=0;
        for(int j=i;j<s.length();j++){
           if(j>i && s[i]=='0')return; 
          currstr+=s[j];
          num=num*10+s[j]-'0';
          if(i==0) solve(ans,s,target,j+1,path+currstr,num,num);
          else{
             solve(ans,s,target,j+1,path+"+"+currstr,eval+num,num);
             solve(ans,s,target,j+1,path+"-"+currstr,eval-num,-num);
             solve(ans,s,target,j+1,path+"*"+currstr,((eval-resd)+(resd*num)),resd*num);
          }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        solve(ans,num,target,0,"",0,0);
        return ans;
    }

};