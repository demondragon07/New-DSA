class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
         for(int i=0;i<n;i++){
            rotate(s.begin(),s.begin()+i,s.end());
            if(s==goal)return true;
            rotate(s.begin(),s.begin()+n-i,s.end());
         }
         return false;
    }
};