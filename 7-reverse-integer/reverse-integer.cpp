class Solution {
public:
    int reverse(int x) {
        int start=0;
        bool negative=false;
         string s=to_string(x);
         int n=s.length();
         string ans;
         if(s[0]=='-'){
           negative=true;
           start=1;
         }
         for(int i=n-1;i>=start;i--){
           ans.push_back(s[i]);
         }
         int result=0;
      try{
       result=stoi(ans);
      }catch(const exception&e){
        result=0;
      } 
      if(negative) result=-result;
      return result;
    }
};