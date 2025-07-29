class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        string p=s;
        for(int i=0;i<n;i++){
            rotate(p.begin(),p.end()-i,p.end());
            if(p.compare(goal)==0){
                return true;
            }
            p=s;
        }
        return false;
    }
};